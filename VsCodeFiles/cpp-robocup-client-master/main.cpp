/****************************************
* Student Name:		Rina Fridland & Shirly Bittan
* Exercise Name:	ex6
* File description:	the robocup soccer team main file
****************************************/

#include "Team.h"

/*********************************************************************
 * Program name:	RoboCup team
 *
 * The operation:	Creates a robocup team "Donatello", connects to
 * 		server and plays the game.
 *********************************************************************/
int main(int argc, char**argv) {
	Team team = Team();
	team.enterGame();
	team.exit();
	return 0;
}
