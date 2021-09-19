/****************************************
 * Student Name:		Rina Fridland & Shirly Bittan
 * Exercise Name:		ex 6
 * File description:	The team blackboard - shared information for players
 * 						singleton.
 ****************************************/
#ifndef BLACKBOARD_H_
#define BLACKBOARD_H_

#include <iostream>
#include <map>

#define STRIKERS_NUM 11
using namespace std;

class Blackboard {
private:
	static Blackboard *instance;
	bool goalieHoldsBall;
	map<unsigned int, float> strikersBallDists;
	map<unsigned int, float> defendersBallDists;
	Blackboard();

public:
	static Blackboard* getInstance();	// singleton getter for instance
	virtual ~Blackboard();

	unsigned int getClosestStriker();	// gets the closest striker to the ball
	void setStrikerDist(unsigned int, float);	// sets distance from ball to the striker
	unsigned int getClosestDefender();	// gets the closest striker to the ball
	void setDefenderDist(unsigned int, float);	// sets distance from ball to the striker

	// Getters/setters:

	bool isCatch() const {
		return goalieHoldsBall;
	}

	void ourCatch() {
		goalieHoldsBall = true;
	}

	void ourThrow() {
		goalieHoldsBall = false;
	}
};

#endif /* BLACKBOARD_H_ */
