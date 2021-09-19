/****************************************
 * Student Name:		Rina Fridland & Shirly Bittan
 * Exercise Name:		ex3
 * File description:	this class handles the player's thinking
 ****************************************/

#include "PlayerBrain.h"

#include <cctype>
#include <sstream>

#include "Blackboard.h"
#include "enumPlayMode.h"
#include "RoboPlayer.h"

// Message types:
#define INIT			"init "
#define	SERVER_PARAM 	"server_param "
#define PLAYER_TYPE 	"player_type (id 0)"
#define PLAYER_PARAM 	"player_param "
#define SENSE_BODY 		"sense_body "
#define HEAR 			"hear "
#define SEE 			"see "
#define BAD_SEE_MSG		"(see 0)"

// Referee directions:
#define KICK_OFF		"referee kick_off_"
#define PLAY_ON			"referee play_on"
#define GOAL			"referee goal_"
#define BEFORE_KICK_OFF "before_kick_off)"
#define GAME_OVER		"time_over"

// Interesting info in a message
#define BALL_FLAG		"(b)"
#define KICKABLE_MARGIN "kickable_margin "
#define HEAD_ANG		"head_angle"
#define LAST_CYCLE		3000

#define SIDE_IND 		6
#define ASCII_0			48
#define MINUS			'-'
#define FLOATING_POINT	'.'

PlayerBrain::PlayerBrain(RoboPlayer& playerRef) : player(playerRef) {
	msg = string();
	requestToMake = string();
	messageType = hear;
}

PlayerBrain::~PlayerBrain() {}

/*************************************************************************
* Function name:	getNumberAfter
* The Input:		index in the message
* The Output:		the first float number after index i
* The Function operation:	gets the first number after i index
* 		also sets i to be the index after that number
*************************************************************************/
float PlayerBrain::getNumberAfter(string::size_type& i) {
	// If not a digit - go on until we get to it
	while (!isdigit(msg[i]) && (msg[i] != '-')) {
		i++;
	}

	// Check if number is negative
	int sign = 1;
	if (msg[i] == MINUS) {
		sign = -1;
		i++;
	}

	// Append digits until floating point
	float res = msg[i] - ASCII_0;
	i++;
	while (isdigit(msg[i])) {
		res *= 10;
		res += msg[i] - ASCII_0;
		i++;
	}

	// Append digits after floating point until the last digit
	if (msg[i] == FLOATING_POINT) {
		float mask = 0.1;
		i++;
		while (isdigit(msg[i])) {
			res += mask * (msg[i] - ASCII_0);
			mask *= 0.1;
			i++;
		}
	}

	// Return the result. Multiply by -1 if negative.
	return res * sign;
}

/*************************************************************************
* Function name:	parse
* The Input:		-
* The Output:		-
* The Function operation: the main method of this class. Parses the message
* 		according to it's type and update player's data. Set a command if needed.
*************************************************************************/
void PlayerBrain::think() {
	// If the game is over - quit
	string::size_type cycleInd = 0;
	if (getNumberAfter(cycleInd) == LAST_CYCLE) {
		requestToMake = player.quit();
		return;
	}

	// Parse the message according to it's type
	switch (messageType) {
	case init: {		// initialization message
		if (msg.find(BEFORE_KICK_OFF) != string::npos) {
			// Initialize the game
			player.setPlayMode(beforeKickOff);
			player.setSide(msg[SIDE_IND]);
			string::size_type ind = 0;
			player.setUnum(getNumberAfter(ind));
			requestToMake = player.teleport();
		}
	}
		break;
	case playerType: {	// player specs message
		// Get the kickable margin of our player
		string::size_type ind = msg.find(KICKABLE_MARGIN);
		player.setKickableMargin(getNumberAfter(ind));
	}
		break;

	case hear: {		// aural message from other robots
		// Change the game mode if referee announces it
		if ((msg.find(PLAY_ON) != string::npos)){
//				|| (msg.find(KICK_OFF) != string::npos)) {
			player.setPlayMode(playOn);
		} else if ((msg.find(ourCatchStr()) != string::npos)
					|| (msg.find(KICK_OFF) != string::npos)) {
				Blackboard::getInstance()->ourCatch();
		} else if (msg.find(GOAL) != string::npos) {
			player.setPlayMode(goal);
			requestToMake = player.teleport();
		} else if (msg.find(GAME_OVER) != string::npos) {
			requestToMake = player.quit();
		}
	}
		break;
	case senseBody: {	// player's physical status message
		// Get the head angle of the player
		string::size_type headAngleInd = msg.find(HEAD_ANG);
		player.setHeadAng(getNumberAfter(headAngleInd));
	}
		break;
	case see:			// current sight information message
		break;
	default:
		break;
	}
}

/*************************************************************************
* Function name:	madeRequest
* The Input:		-
* The Output:		true if parser generated proper command for the player
* The Function operation: checks if a request was generated
*************************************************************************/
bool PlayerBrain::madeRequest() {
	return !requestToMake.empty();
}

/*************************************************************************
* Function name:	setMsg
* The Input:		message
* The Output:		-
* The Function operation: sets the last server message to parse
*************************************************************************/
void PlayerBrain::setMsg(const string& msg) {
	this->msg = msg;

	// Get the message type
	if(msg.find(INIT) == 1) {
		messageType = init;
	} else if (msg.find(SERVER_PARAM) == 1) {
		messageType = serverParam;
	} else if (msg.find(PLAYER_PARAM) == 1) {
		messageType = playerParam;
	} else if (msg.find(PLAYER_TYPE) == 1) {
		messageType = playerType;
	} else if (msg.find(SENSE_BODY) == 1) {
		messageType = senseBody;
	} else if (msg.find(HEAR) == 1) {
		messageType = hear;
	} else if ((msg.find(SEE) == 1) &&
			(msg.find(BAD_SEE_MSG) == string::npos)) {
		messageType = see;
	}
}

const string PlayerBrain::getRequestToMake() {
	const string req = requestToMake;
	requestToMake = string();
	return req;
}

/*************************************************************************
* Function name:	operator++
* The Input:		-
* The Output:		this
* The Function operation: makes the parser parse the message.
*************************************************************************/
PlayerBrain& PlayerBrain::operator++() {
	think();
	return *this;
}

/*************************************************************************
* Function name:	ourCatchStr
* The Input:		-
* The Output:		the string we get when our goalie catches the ball
* The Function operation: returns the string we get when our goalie catches the ball
*************************************************************************/
string PlayerBrain::ourCatchStr() {
	ostringstream stream;
	const string START = "free_kick_";
	stream << START << player.getSide();
	return stream.str();
}
