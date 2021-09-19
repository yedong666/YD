/****************************************
 * Student Name:		Rina Fridland & Shirly Bittan
 * Exercise Name:		ex6
 * File description:	represents the striker thinking techniques
 ****************************************/

#include "StrikerBrain.h"

#include <sstream>

#include "Blackboard.h"
#include "enumMsgType.h"
#include "enumPlayMode.h"
#include "RoboPlayer.h"

// Referee directions:
#define KICK_OFF		"referee kick_off_"
#define PLAY_ON			"referee play_on"
#define GOAL			"referee goal_"
#define BEFORE_KICK_OFF "before_kick_off)"

// Interesting info in a message
#define BALL_FLAG		"(b)"

#define MAX_DIST		100
#define MIN_GATES_DIST	20

StrikerBrain::StrikerBrain(RoboPlayer& playerRef, bool isPassive) : PlayerBrain(playerRef) {
	isPlaced = false;
	Blackboard::getInstance()->setStrikerDist(player.getUnum(), MAX_DIST);
	if (isPassive) {
		player.setPassive();
	} else {
		player.setActive();
	}
}

StrikerBrain::~StrikerBrain() {}

/*************************************************************************
* Function name:	goalFlag
* The Input:		-
* The Output:		string - the opponent's goal flag
* The Function operation: gets the goal flag of the opponent according to
* 		side of the player.
*************************************************************************/
string StrikerBrain::goalFlag() {
	ostringstream stream;
	const string START = "(g ";
	const string END = ")";
	stream << START << player.getEnemySide() << END;
	return stream.str();
}

/*************************************************************************
* Function name:	goalTopFlag
* The Input:		-
* The Output:		string - the opponent's top of gate flag
* The Function operation: gets the gate top flag of the opponent according to
* 		side of the player.
*************************************************************************/
string StrikerBrain::goalTopFlag() {
	ostringstream stream;
	const string START = "(f g ";
	const string END = " t)";
	stream << START << player.getEnemySide() << END;
	return stream.str();
}

/*************************************************************************
* Function name:	goalBottomFlag
* The Input:		-
* The Output:		string - the opponent's bottom of gate flag
* The Function operation: gets the gate bottom flag of the opponent according to
* 		side of the player.
*************************************************************************/
string StrikerBrain::goalBottomFlag() {
	ostringstream stream;
	const string START = "(f g ";
	const string END = " b)";
	stream << START << player.getEnemySide() << END;
	return stream.str();
}

/*************************************************************************
* Function name:	kickBall
* The Input:		-
* The Output:		-
* The Function operation: sets a proper command if the player has to kick a ball:
* 		kick it towards the goal if he sees it, or turn it.
*************************************************************************/
void StrikerBrain::kickBall() {
	string::size_type gInd = msg.find(goalFlag());
	string::size_type gtInd = msg.find(goalTopFlag());
	string::size_type gbInd = msg.find(goalBottomFlag());

	// If can't see the goal at all, softly kick the ball to turn it and quit
	if (gInd == string::npos && gtInd == string::npos && gbInd == string::npos) {
		requestToMake = player.softSideKick();
		return;
	}

	// Can see the goal. Check which spot of the gates we see
	string::size_type seenGoal;
	if (gInd != string::npos) {
		seenGoal = gInd;
	} else if (gtInd == string::npos) {
		seenGoal = gtInd;
	} else {
		seenGoal = gbInd;
	}

	// Get goal direction and kick the ball there
	getNumberAfter(seenGoal);
	float goalDir = getNumberAfter(seenGoal);
	requestToMake = player.maxKickTo(goalDir);
}

/*************************************************************************
* Function name:	StrikerBrain::runToPosition
* The Input:		-
* The Output:		true if got to position, false if has to run more
* The Function operation: passive striker runs to it's position
*************************************************************************/
bool StrikerBrain::runToPosition() {
	string::size_type currInd = msg.find(goalFlag());

	// If can't see the goal - turn right
	if (currInd == string::npos) {
		requestToMake = player.turnRight();
		return false;
	}

	// If the goal is close enough - stop
	if (getNumberAfter(currInd) <= MIN_GATES_DIST) {
		return true;
	}

	// Run to goal
	float goalDir = getNumberAfter(currInd);
	if (goalDir != 0) {
		requestToMake = player.turn(goalDir); // turn to the goal
	} else {
		requestToMake = player.maxSpeedDash(); // run to the goal
	}
	return false;
}

/*************************************************************************
* Function name:	StrikerBrain::chaseBall
* The Input:		ball index in string, ball distance from striker
* The Output:		void
* The Function operation: striker chases the ball and hits
*************************************************************************/
void StrikerBrain::chaseBall(string::size_type ballInd, float ballDist) {
	// Turn to the ball if needed
	float ballDir = getNumberAfter(ballInd);
	if (ballDir != 0) {
		requestToMake = player.turn(ballDir);

		// If we're in the game - get the ball
	} else if (player.getPlayMode() == playOn) {
		if (ballDist < player.getKickableMargin()) {
			kickBall(); // ball is close enough to kick
		} else {
			requestToMake = player.maxSpeedDash();
		}
	}
}

/*************************************************************************
* Function name:	react
* The Input:		-
* The Output:		-
* The Function operation: choses the right action according to current field
* 		and player's sight information
*************************************************************************/
void StrikerBrain::react() {
	// If passive - run to his position. When got there - turn active
	if (player.isNowPassive() && !isPlaced) {
		isPlaced = runToPosition();
		if (!isPlaced) {
			return;
		}
	}

	// Player is active
	string::size_type ballInd = msg.find(BALL_FLAG); // get the index of ball flag in the string
	Blackboard* blackboard = Blackboard::getInstance();
	unsigned int unum = player.getUnum();

	// If the player can't see the ball - search for it
	if (ballInd == string::npos) {
		requestToMake = player.turnRight();
		blackboard->setStrikerDist(unum, MAX_DIST); // ball's distance unknown
		return;
	}

	// Ball found. Parse it's info
	float ballDist = getNumberAfter(ballInd);
	blackboard->setStrikerDist(unum, ballDist); // Update striker's ball distance

	// If striker is closest to the ball - he chases the ball
	if (unum == blackboard->getClosestStriker()) {
		chaseBall(ballInd, ballDist);
	}
}
/*************************************************************************
* Function name:	think
* The Input:		void
* The Output:		void
* The Function operation: reacts to field and makes decisions
*************************************************************************/
void StrikerBrain::think() {
	PlayerBrain::think();

	switch (messageType){
	case see:
		react(); // react to what we see
		break;
	case hear:
		if ((msg.find(PLAY_ON) != string::npos)
				|| (msg.find(KICK_OFF) != string::npos)
				|| (msg.find(GOAL) != string::npos)) {
			// in case of play renewal - players move to start point
			isPlaced = false;
		}
		break;
	default:
		break;
	}
}
