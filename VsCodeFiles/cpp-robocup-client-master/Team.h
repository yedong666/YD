/****************************************
 * Student Name:		Rina Fridland & Shirly Bittan
 * Exercise Name:		ex6
 * File description:	represents the robocup Donatello team
 ****************************************/
#ifndef TEAM_H_
#define TEAM_H_

#include <string>
#include <vector>

#include "RobocupClient.h"
#include "RoboPlayer.h"

class Goalie;

class Team {
private:
	string name;
	RoboPlayer* goalKeeper;
	vector<RoboPlayer*> strikers;
	vector<RoboPlayer*> defenders;
	vector<RoboPlayer*> players;
	vector<RobocupClient*> playerClients;

public:
	Team();
	virtual ~Team();

	void enterGame();	// the tem enters the game and starts playing
	void disconnect();	// disconnects from the game
	void exit();		// quit (destroyes all threads)

	// team name getter
	const string& getName() const {
		return name;
	}
};

#endif /* TEAM_H_ */
