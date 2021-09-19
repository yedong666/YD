/****************************************
 * Student Name:		Rina Fridland & Shirly Bittan
 * Exercise Name:		ex6
 * File description:	represents the defender thinking
 ****************************************/

#include "DefenderBrain.h"

#include <sstream>
#include <string>

#include "Blackboard.h"
#include "enumMsgType.h"
#include "enumPlayMode.h"
#include "RoboPlayer.h"

#define BALL_FLAG		"(b)"
#define CLOSE			')'
#define MAX_DIST		100
#define MIN_DIR			15.0
#define MIN_DIST		12.0

DefenderBrain::DefenderBrain(RoboPlayer& playerRef) : PlayerBrain(playerRef) {
	Blackboard::getInstance()->setDefenderDist(playerRef.getUnum(), MAX_DIST);
}

DefenderBrain::~DefenderBrain() {}

/*************************************************************************
* Function name:	enemyLine
* The Input:		-
* The Output:		string - the enemy line flag
* The Function operation: returns the enemy line flag
*************************************************************************/
string DefenderBrain::enemyLine() {
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
void DefenderBrain::kickBall() {
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

/*************************************************************************
* Function name:	react
* The Input:		-
* The Output:		-
* The Function operation: react to what player sees
*************************************************************************/
void DefenderBrain::react() {
	string::size_type currInd = msg.find(BALL_FLAG); // get the index of ball flag in the string
	Blackboard* blackboard = Blackboard::getInstance();
	unsigned int unum = player.getUnum();

	// If the player can't see the ball - search for it
	if (currInd == string::npos) {
		requestToMake = player.turnRight();
		blackboard->setDefenderDist(unum, MAX_DIST);
		return;
	}

	// Ball found. Parse ball info
	float ballDist = getNumberAfter(currInd);
	float ballDir = getNumberAfter(currInd);
	blackboard->setDefenderDist(unum, ballDist); // update ball dist in blackboard

	// If we don't see more info - ball is too far.
	if (msg[currInd] == CLOSE) {
		return;
	}

	// Check the distance change. If positive - ball is running away (not relevant)
	float distChange = getNumberAfter(currInd);
	if (distChange > 0) {
		return;
	}

	// Turn to the ball if needed
	if (ballDir > MIN_DIR && ballDir < (-1 * MIN_DIR)) {
		requestToMake = player.turn(ballDir);
		return;
	}

	// If we're in the game and it's the closest defender - get the ball
	if (player.getPlayMode() == playOn &&
			blackboard->getClosestDefender() == unum) {
		// If ball is close enough - kick it or run to it
		if (ballDist < player.getKickableMargin()) {
			kickBall();
		} else if (ballDist < MIN_DIST) {
			requestToMake = player.maxSpeedDash();
		}
	}
}

/*************************************************************************
* Function name:	DefenderBrain::think
* The Input:		void
* The Output:		void
* The Function operation: reacts to field and makes decisions
*************************************************************************/
void DefenderBrain::think() {
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
