/****************************************
 * Student Name:		Rina Fridland & Shirly Bittan
 * Exercise Name:		ex6
 * File description:	represents the goalie thinking techniques
 ****************************************/
#ifndef GOALIEBRAIN_H_
#define GOALIEBRAIN_H_

#include "PlayerBrain.h"

class GoalieBrain: public PlayerBrain {
private:
	string enemyLine();	// return the enemy line flag
	void kickBall();	// kick the ball towards enemy line
	void react();		// react to what player sees

public:
	GoalieBrain(RoboPlayer&);
	virtual ~GoalieBrain();
	void think();	// think what to do in current fied and make decisions
};

#endif /* GOALIEBRAIN_H_ */
