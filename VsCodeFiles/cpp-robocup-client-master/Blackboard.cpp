/****************************************
 * Student Name:		Rina Fridland & Shirly Bittan
 * Exercise Name:		ex 6
 * File description:	The team blackboard - shared information for players
 * 						singleton.
 ****************************************/
#include <cstddef>
#include "Blackboard.h"

#define MAX_DIST 100

Blackboard* Blackboard::instance = NULL;

Blackboard::Blackboard() {
	goalieHoldsBall = false;
}

/*************************************************************************
* Function name:	gitInstance
* The Input:		none
* The Output:		blackboard instance
* The Function operation: singleton - returns the one and only instance of
* 			the blackboard to share between all players
*************************************************************************/
Blackboard* Blackboard::getInstance() {
	if (!instance) {
		instance = new Blackboard();
	}
	return instance;
}

Blackboard::~Blackboard() {
}

/*************************************************************************
* Function name:	Blackboard::getClosestStriker
* The Input:		-
* The Output:		closest striker uniform number
* The Function operation: finds which striker is closest to the ball
*************************************************************************/
unsigned int Blackboard::getClosestStriker() {
	float minDist = MAX_DIST;
	unsigned int unum;

	// Go over the strikers and find the closest one to the ball
	map<unsigned int, float>::iterator striker;
	for (striker = strikersBallDists.begin(); striker != strikersBallDists.end(); ++striker) {
		// If dist is smaller - save it
		if (striker->second < minDist) {
			minDist = striker->second;
			unum = striker->first;
		}
	}
	return unum;
}

/*************************************************************************
* Function name:	Blackboard::setStrikerDist
* The Input:		the player's number and ball distance
* The Output:		void
* The Function operation: updates the distance from ball
*************************************************************************/
void Blackboard::setStrikerDist(unsigned int unum, float dist) {
	strikersBallDists[unum] = dist;
}

/*************************************************************************
* Function name:	Blackboard::getClosestDefender
* The Input:		-
* The Output:		closest defender uniform number
* The Function operation: finds which defender is closest to the ball
*************************************************************************/
unsigned int Blackboard::getClosestDefender() {
	float minDist = MAX_DIST;
	unsigned int unum;

	// Go over the strikers and find the closest one to the ball
	map<unsigned int, float>::iterator currDef;
	for (currDef = defendersBallDists.begin(); currDef != defendersBallDists.end(); ++currDef) {
		// If dist is smaller - save it
		if (currDef->second < minDist) {
			minDist = currDef->second;
			unum = currDef->first;
		}
	}
	return unum;
}
/*************************************************************************
* Function name:	Blackboard::setDefenderDist
* The Input:		the player's number and ball distance
* The Output:		void
* The Function operation: updates the distance from ball
*************************************************************************/
void Blackboard::setDefenderDist(unsigned int unum, float dist) {
	defendersBallDists[unum] = dist;
}
