/****************************************
 * Student Name:		Rina Fridland & Shirly Bittan
 * Exercise Name:		ex3
 * File description:	Represents a robocup player.
 * 		Holds his attributes and generates action strings.
 ****************************************/

#include "RoboPlayer.h"
#include <sstream>
#include "PlayerFactory.h"

// Commands syntax:
#define INIT			"(init "
#define VERSION			" (version 15))"
#define EXIT_COMMAND	"(bye)"
#define TURN			"(turn "
#define TURN_NECK		"(turn_neck "
#define DASH			"(dash "
#define MOVE			"(move "
#define KICK			"(kick "
#define CATCH			"(catch "
#define CLOSE			")"

RoboPlayer::RoboPlayer(string x, string y, playerRole role, string teamName) {
	this->teamName = teamName;
	this->role = role;
	startX = x;
	startY = y;
	exited = false;
	unum = 0;
	isPassive = false;

	// Initialize player status
	ballDir = 0;
	ballDist = 100;
	headAng = 0;
	side = 0;
	kickableMargin = 0;
	playMode = notStarted;
}

RoboPlayer::~RoboPlayer() {}

/*************************************************************************
* Function name:	newPlayer
* The Input:		void
* The Output:		the new player command string
* The Function operation:	get the new player string
*************************************************************************/
string RoboPlayer::newPlayer() {
	// "(move x y)"
	ostringstream stream;
	stream << INIT << teamName << VERSION;
	return stream.str();
}

/*************************************************************************
* Function name:	teleport
* The Input:		void
* The Output:		the teleport command
* The Function operation:	get command to teleport the player to start pos
*************************************************************************/
string RoboPlayer::teleport() {
	// "(move x y)"
	ostringstream stream;
	stream << MOVE << startX << " " << startY << CLOSE;
	return stream.str();
}

/*************************************************************************
* Function name:	dash
* The Input:		power (velocity) to dash
* The Output:		dash command
* The Function operation: get the dash command string with spec. power
*************************************************************************/
string RoboPlayer::dash(float power) {
	// "(dash power)"
	ostringstream stream;
	stream << DASH << power << CLOSE;
	return stream.str();
}

/*************************************************************************
* Function name:	maxSpeedDash
* The Input:		void
* The Output:		dash command with maximum speed
* The Function operation:	Get the command to dash woth max speed
*************************************************************************/
string RoboPlayer::maxSpeedDash() {
	const int MAX_SPEED = 100;
	return dash(MAX_SPEED);
}

/*************************************************************************
* Function name:	turn
* The Input:		direction to turn to (relative to body angle)
* The Output:		turn command string
* The Function operation:	gets command to turn the player
*************************************************************************/
string RoboPlayer::turn(float direction) {
	// "(turn direction)"
	ostringstream stream;
	stream << TURN << direction << CLOSE;
	return stream.str();
}

/*************************************************************************
* Function name:	turnRight
* The Input:		void
* The Output:		turn to right command string
* The Function operation:	gets command to turn right relative to player's angle
*************************************************************************/
string RoboPlayer::turnRight() {
	const int RIGHT_DIR = 90;

	ostringstream stream;
	stream << TURN << RIGHT_DIR << CLOSE;
	return stream.str();
}

/*************************************************************************
* Function name:	turnNeck
* The Input:		direction to turn to (relative to body angle)
* The Output:		turn neck command string
* The Function operation:	gets command to turn neck
*************************************************************************/
string RoboPlayer::turnNeck(float direction) {
	// "(turn_neck direction)"
	ostringstream stream;
	stream << TURN_NECK << direction << CLOSE;
	return stream.str();
}

/*************************************************************************
* Function name:	kick
* The Input:		power to kick with
* 					direction to kick to
* The Output:		kick ball command
* The Function operation:	gets command to kick the ball
*************************************************************************/
string RoboPlayer::kick(float power, float direction) {
	// "(kick power direction)"
	ostringstream stream;
	stream << KICK << power << " " << direction << CLOSE;
	return stream.str();
}
/*************************************************************************
* Function name:	softSideKick
* The Input:		void
* The Output:		kick command
* The Function operation:	gets command to kick the ball to side very softly,
* 		in order to turn it back if needed.
*************************************************************************/
string RoboPlayer::softSideKick() {
	const int POWER = 3;
	const int DIRECTION = 90;
	return kick(POWER, DIRECTION);
}

/*************************************************************************
* Function name:	softKickTo
* The Input:		direction to kick to
* The Output:		kick command
* The Function operation:	gets command to kick the ball softly to spec. direction
*************************************************************************/
string RoboPlayer::softKickTo(float direction) {
	const int POWER = 20;
	return kick(POWER, direction);
}

/*************************************************************************
* Function name:	catchBall
* The Input:		direction to catch
* The Output:		catch command
* The Function operation:	gets command to catch the ball - only relevant to goalie.
*************************************************************************/
string RoboPlayer::catchBall(float direction) {
	// "(catch direction)"
	ostringstream stream;
	stream << CATCH << direction << CLOSE;
	return stream.str();
}

/*************************************************************************
* Function name:	maxKickTo
* The Input:		direction to kick to
* The Output:		kick command
* The Function operation:	gets command to kick the ball to spec. direction
* 	with maximum power.
*************************************************************************/
string RoboPlayer::maxKickTo(float direction) {
	const int MAX_POWER = 100;
	return kick(MAX_POWER, direction);
}

/*************************************************************************
* Function name:	quit
* The Input:		-
* The Output:		quit command
* The Function operation:	gets command to disconnect from server.
*************************************************************************/
string RoboPlayer::quit() {
	exited = true;
	return EXIT_COMMAND;
}

/*************************************************************************
* Function name:	RoboPlayer::getBrain
* The Input:		-
* The Output:		pointer to the player's brain
* The Function operation: creates brain and returns it
*************************************************************************/
PlayerBrain* RoboPlayer::getBrain() {
	PlayerFactory factory = PlayerFactory();
	return factory.getBrain(*this);
}
