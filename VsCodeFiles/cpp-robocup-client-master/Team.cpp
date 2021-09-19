/****************************************
 * Student Name:		Rina Fridland & Shirly Bittan
 * Exercise Name:		ex6
 * File description:	represents the robocup Donatello team
 ****************************************/

#include "Team.h"
#include "enumPlayerRole.h"

#define TEAM_NAME	"Donatello"
#define MINUS		"-"

/*************************************************************************
* Function name:	Team
* The Input:		-
* The Output:		-
* The Function operation: Creates a team
*************************************************************************/
Team::Team() {
	name = TEAM_NAME;

	// Positions:
	//守门员(goalie)
	const string GOALIE_X = "-50";
	const string GOALIE_Y = "0";

	//前锋坐标(striker)
	const string S1_X = "-9";
	const string S1_Y = "2";
	const string S2_X = "-3";
	const string S2_Y = "30";

	//后卫坐标(defender)
	const string D1_X = "-30";
	const string D1_Y = "30";
	const string D2_X = "-33";
	const string D2_Y = "15";
	const string D3_X = "-36";
	const string D3_Y = "5";

	// Create the goalie:
	goalKeeper = new RoboPlayer(GOALIE_X, GOALIE_Y, goalie, name);

	// Create the strikers:
	strikers.push_back(new RoboPlayer(S1_X, S1_Y, activeStriker, name));
	strikers.push_back(new RoboPlayer(S1_X, MINUS + S1_Y, activeStriker, name));
	strikers.push_back(new RoboPlayer(S2_X, S2_Y, passiveStriker, name));
	strikers.push_back(new RoboPlayer(S2_X, MINUS + S2_Y, passiveStriker, name));

	// Create the defenders:
	defenders.push_back(new RoboPlayer(D1_X, D1_Y, defender, name));
	defenders.push_back(new RoboPlayer(D1_X, MINUS + D1_Y, defender, name));
	defenders.push_back(new RoboPlayer(D2_X, D2_Y, defender, name));
	defenders.push_back(new RoboPlayer(D2_X, MINUS + D2_Y, defender, name));
	defenders.push_back(new RoboPlayer(D3_X, D3_Y, defender, name));
	defenders.push_back(new RoboPlayer(D3_X, MINUS + D3_Y, defender, name));

	// Add all the players to one collection
	players.push_back(goalKeeper);
	vector<RoboPlayer*>::iterator player;
	for (player = strikers.begin(); player != strikers.end(); ++player) {
		players.push_back(*player);
	}
	for (player = defenders.begin(); player != defenders.end(); ++player) {
		players.push_back(*player);
	}
}

Team::~Team() {
	// Delete all players
	vector<RoboPlayer*>::iterator player;
	for (player = players.begin(); player != players.end(); ++player) {
		delete *player;
	}

	// Delete all clients
	vector<RobocupClient*>::iterator client;
	for (client = playerClients.begin(); client != playerClients.end(); ++client) {
		delete *player;
	}
}

/*************************************************************************
* Function name:	Team::enterGame
* The Input:		void
* The Output:		void
* The Function operation: The team enters game - clients are created for
* 	each player and connected to server
*************************************************************************/
void Team::enterGame() {
	// Create clients for server communication for each player
	/*
		所谓进入游戏，即对RoboPlayer类型的球员对象进行更深层次的封装
		使每个球员成为独立的客户端，拥有自己的输入(接收外部信息，信息可能来自其他球员客户端，服务器，教练等)
		与输出系统(对外发出信息)，即两个线程
	*/
	vector<RoboPlayer*>::iterator player;
	for (player = players.begin(); player != players.end(); ++player) {
		playerClients.push_back(new RobocupClient(**player));
	}
}

/*************************************************************************
* Function name:	disconnect
* The Input:		-
* The Output:		-
* The Function operation: sends exit request from all clients and disconnect from game
*************************************************************************/
void Team::disconnect() {
	// Stop all the clients
	vector<RobocupClient*>::iterator client;
	for (client = playerClients.begin(); client != playerClients.end(); ++client) {
		(*client)->setRequest((*client)->getPlayer().quit());
	}
}

/*************************************************************************
* Function name:	exit
* The Input:		-
* The Output:		-
* The Function operation: stops all recieving threads in disconnected game
*************************************************************************/
void Team::exit() {
	vector<RobocupClient*>::iterator client;
	for (client = playerClients.begin(); client != playerClients.end(); ++client) {
		// When client stops requesting - stop recieving
		(*client)->joinReqesting();
		(*client)->stopRecieving();
	}
}
