/****************************************
 * Student Name:		Rina Fridland & Shirly Bittan
 * Exercise Name:		ex3
 * File description:	this class handles parsing the robocup server's messages.
 ****************************************/

#ifndef SERVERMSGPARSER_H_
#define SERVERMSGPARSER_H_

#include <string>
#include "enumMsgType.h"
class RoboPlayer;
using namespace std;

class PlayerBrain {
protected:
	string msg;
	RoboPlayer &player;
	MsgType messageType;
	string requestToMake;

	string ourCatchStr();
	float getNumberAfter(string::size_type&);	// get next float number after index

public:
	PlayerBrain(RoboPlayer&);
	virtual ~PlayerBrain();

	virtual void think();		// parses the message
	bool madeRequest();	// checks if request was made
	void setMsg(const string&);
	const string getRequestToMake(); // Getter for request string

	// Note: note necessary! Just to use operator overloading in the assignment
	PlayerBrain& operator++();

};

#endif
