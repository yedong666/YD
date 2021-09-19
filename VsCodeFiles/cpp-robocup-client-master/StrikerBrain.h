/****************************************
 * Student Name:		Rina Fridland & Shirly Bittan
 * Exercise Name:		ex6
 * File description:	represents the defender thinking techniques
 ****************************************/
#ifndef STRIKERBRAIN_H_
#define STRIKERBRAIN_H_

#include <string>
#include "PlayerBrain.h"

using namespace std;
class StrikerBrain: public PlayerBrain {
private:
	bool isPlaced;

	void kickBall();			// player has to kick the ball. Generate proper command
	void react();				// choose how to react to situation on field
	string goalFlag();			// gets the opponent gate flag
	string goalTopFlag();		// gets the opponent gate top flag
	string goalBottomFlag();	// gets the opponent gate bottom flag
	bool runToPosition();		// passive striker runs to its position
	void chaseBall(string::size_type currInd, float ballDist); // chases the ball and kicks it

public:
	StrikerBrain(RoboPlayer&, bool);
	virtual ~StrikerBrain();

	void think();	// thinking what to do next
};

#endif /* STRIKERBRAIN_H_ */
