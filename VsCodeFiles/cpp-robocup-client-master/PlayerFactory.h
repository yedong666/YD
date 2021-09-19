/****************************************
 * Student Name:		Rina Fridland & Shirly Bittan
 * Exercise Name:		ex 6
 * File description:	player brain factory XD
 * 			creates brain according to player's role
 ****************************************/
#ifndef PLAYERFACTORY_H_
#define PLAYERFACTORY_H_

class PlayerBrain;
class RoboPlayer;

using namespace std;

class PlayerFactory {
public:
	PlayerFactory();
	virtual ~PlayerFactory();

	PlayerBrain* getBrain(RoboPlayer&); // returns a brain for the player
};

#endif /* PLAYERFACTORY_H_ */
