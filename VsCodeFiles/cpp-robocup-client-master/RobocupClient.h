/****************************************
 * Student Name:		Rina Fridland & Shirly Bittan
 * Exercise Name:		ex3
 * File description:	Client for robocup.
 * 		Handles communicating with the server.
 ****************************************/

#ifndef ROBOCUP_CLIENT_H_
#define ROBOCUP_CLIENT_H_

#include <pthread.h>
#include <queue>
#include <string>

#include "enumPlayMode.h"
#include "RoboPlayer.h"
#include "PlayerBrain.h"

class ISocket;

using namespace std;

class RobocupClient {
private:
	ISocket		*client;
	RoboPlayer 	&player;
	string		nextRequest;
	pthread_t 	requesterThread;
	pthread_t 	recieverThread;
	PlayerBrain *brain;

	static void sendCommandsToServer(RobocupClient*);	// thread function - sends messages
	static void recieveServerMessages(RobocupClient*); // thread function - recieves messages

	// Note: this isn't necessary, just added to use STL in the assignment.
	// Just holds a queue of requests that were sent.
	queue<string> requests;

public:
	RobocupClient(RoboPlayer&);
	virtual ~RobocupClient();

	string 	recieve();			// recieves a message from server
	bool 	send();				// sends a command to server
	void 	setRequest(string);	// sets a request to send

	// Multithread sending/recieving:
	void 	startRequesting();	// creates a thread that sends requests to server
	void 	startRecieving();	// creates a thread that recieves the server messages
	void 	joinReqesting();	// waits until requesting thread exits
	void 	stopRecieving();	// stops the recieving thread

	// Getters

	RoboPlayer& getPlayer() {
		return player;
	}

	PlayerBrain* getBrain() const {
		return brain;
	}
};

#endif /* ROBOCUPCLIENT_H_ */
