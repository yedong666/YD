/****************************************
 * Student Name:		Rina Fridland & Shirly Bittan
 * Exercise Name:		ex6
 * File description:	represents the defender thinking
 ****************************************/
#ifndef DEFENDERBRAIN_H_
#define DEFENDERBRAIN_H_

#include "PlayerBrain.h"

class DefenderBrain: public PlayerBrain {
private:
	string enemyLine();	// return the enemy line flag
	void kickBall();	// kick the ball towards enemy line
	void react();		// react to what player sees

public:
	DefenderBrain(RoboPlayer&);
	virtual ~DefenderBrain();
	void think();	// think what to do next
};

#endif /* DEFENDERBRAIN_H_ */
