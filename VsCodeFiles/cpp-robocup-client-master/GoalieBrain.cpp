/****************************************
 * Student Name:		Rina Fridland & Shirly Bittan
 * Exercise Name:		ex6
 * File description:	represents the goalie thinking techniques
 ****************************************/

#include "GoalieBrain.h"

#include <sstream>
#include <string>

#include "enumMsgType.h"
#include "enumPlayMode.h"
#include "RoboPlayer.h"

#define BALL_FLAG		"(b)"
#define CLOSE			')'
#define CATCHABLE_LENGTH 2.0
#define MIN_DIR			15.0
#define MIN_DIST		8.0

GoalieBrain::GoalieBrain(RoboPlayer& playerRef) : PlayerBrain(playerRef) {}
GoalieBrain::~GoalieBrain() {}

/*************************************************************************
* Function name:	enemyLine
* The Input:		-
* The Output:		string - the enemy line flag
* The Function operation: returns the enemy line flag
*************************************************************************/
string GoalieBrain::enemyLine() {
	ostringstream stream;
	const string START = "(l ";
	const string END = " )";
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
void GoalieBrain::kickBall() {
	string::size_type enemy = msg.find(enemyLine());

	// If can't see the enemy line at all, softly kick the ball to turn it and quit
	if (enemy == string::npos) {
		requestToMake = player.softSideKick();
		return;
	}

	// Can see the enemy line. Get goal direction and kick the ball there
	getNumberAfter(enemy);
	float enemyDir = getNumberAfter(enemy);
	requestToMake = player.maxKickTo(enemyDir);
}

void GoalieBrain::react() {
		string::size_type currInd = msg.find(BALL_FLAG); // get the index of ball flag in the string

		// If the player can't see the ball - search for it
		if (currInd == string::npos) {
			requestToMake = player.turnRight();
			return;
		}

		// Ball found. Parse ball info
		float ballDist = getNumberAfter(currInd);
		float ballDir = getNumberAfter(currInd);

		// If ball is too far - return
		if (msg[currInd] == CLOSE) {
			return;
		}

		// Check the distance change. Chase only if ball is getting closer
		float distChange = getNumberAfter(currInd);
		if (distChange >= 0) {
			return;
		}

		// Turn to the ball if needed
		if (ballDir > MIN_DIR && ballDir < -1 * MIN_DIR) {
			requestToMake = player.turn(ballDir);
		}

		else if (player.getPlayMode() == playOn) {
			// If ball is close enough - kick it
			 if (ballDist < player.getKickableMargin()) {
				kickBall();
			} else if (ballDist < 10.0) {
				requestToMake = player.maxSpeedDash();
			}
		}
}

/*************************************************************************
* Function name:	GoalieBrain::think
* The Input:		void
* The Output:		void
* The Function operation: goalie's logic of making decitions according to
* 		the current situation on field
*************************************************************************/
void GoalieBrain::think() {
	PlayerBrain::think();

	// Parse the message according to it's type
	switch (messageType) {
	case see:			// current sight information message
		react();
		break;
	case init:		// initialization message
	case playerType:	// player specs message
	case hear:		// aural message from other robots
	case senseBody:	// player's physical status message
	default:
		break;
	}
}
