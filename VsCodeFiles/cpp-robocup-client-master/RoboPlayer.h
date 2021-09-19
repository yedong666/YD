/****************************************
 * Student Name:		Rina Fridland & Shirly Bittan
 * Exercise Name:		ex3
 * File description:	Represents a robocup player.
 * 		Holds his attributes and generates action strings.
 ****************************************/

#ifndef ROBOPLAYER_H_
#define ROBOPLAYER_H_

#include <string>
#include "enumPlayerRole.h"
#include "enumPlayMode.h"
#include "Blackboard.h"

class PlayerBrain;
using namespace std;

class RoboPlayer {
private:
	PlayMode playMode;
	string 	teamName;
	string 	startX;
	string 	startY;
	char 	side;
	float 	headAng;
	float 	ballDist;
	float 	ballDir;
	float 	kickableMargin;
	bool 	exited;
	bool 	isPassive;
	playerRole role;
	unsigned int unum;

public:
	RoboPlayer(string, string, playerRole, string);
	virtual ~RoboPlayer();

	string newPlayer();			// gets command to create a new player
	string teleport();			// gets command to move player to his start point
	string dash(float);			// gets command to dash
	string maxSpeedDash();		// gets command to dash with max. speed
	string turn(float);			// gets command to turn
	string turnRight();			// gets command to turn right
	string turnNeck(float);		// gets command to turn only the neck
	string kick(float, float);	// gets command to kick the ball
	string maxKickTo(float);	// gets command to kick with max. power
	string softKickTo(float);	// gets command to kick softly
	string softSideKick();		// gets command to very soft kick to side to turn the ball
	string catchBall(float);	// only goalie - catches the ball in the chosen direction
	string quit();				// gets command to desinnect
	virtual PlayerBrain* getBrain();

	// Getters & setters:

	float getBallDir() const {
		return ballDir;
	}

	template<typename T>
	// NOTE: this is only for purpose of using templates in this assignment.
	// It's not really necessary, so I use it only in this function.
	void setBallDir(T ballDir) {
		this->ballDir = ballDir;
	}

	float getBallDist() const {
		return ballDist;
	}

	void setBallDist(float ballDist) {
		this->ballDist = ballDist;
	}

	float getHeadAng() const {
		return headAng;
	}

	void setHeadAng(float headAng) {
		this->headAng = headAng;
	}

	float getKickableMargin() const {
		return kickableMargin;
	}

	void setKickableMargin(float kickableMargin) {
		this->kickableMargin = kickableMargin;
	}

	PlayMode getPlayMode() const {
		return playMode;
	}

	void setPlayMode(PlayMode playMode) {
		this->playMode = playMode;
	}

	char getSide() const {
		return side;
	}

	void setSide(char side) {
		this->side = side;
	}

	char getEnemySide() {
		if (side == 'l') {
			return 'r';
		}
		return 'l';
	}

	bool hasExited() const {
		return exited;
	}

	playerRole getRole() const {
		return role;
	}

	unsigned int getUnum() const {
		return unum;
	}

	void setUnum(unsigned int unum) {
		this->unum = unum;
	}

	bool isNowPassive() const {
		return isPassive;
	}

	void setPassive() {
		this->isPassive = true;
	}

	void setActive() {
		this->isPassive = false;
	}
};

#endif /* ROBOCUPCLIENT_H_ */
