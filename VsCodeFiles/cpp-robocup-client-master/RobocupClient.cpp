/****************************************
 * Student Name:		Rina Fridland & Shirly Bittan
 * Exercise Name:		ex3
 * File description:	Client for robocup.
 * 		Handles communicating with the server.
 ****************************************/

#include "RobocupClient.h"

#include <pthread.h>
#include <unistd.h>
#include <iostream>
#include "UdpClient.h"

#define PORT			6000
#define REQ_INTERVAL	250000
#define SELF_IP			"127.0.0.1"

RobocupClient::RobocupClient(RoboPlayer &p) : player(p) {
	client = new UdpClient(SELF_IP, PORT);
	recieverThread = 0;
	requesterThread = 0;
	nextRequest = string();
	brain = player.getBrain();
	setRequest(player.newPlayer());
	startRequesting();
	startRecieving();
}

RobocupClient::~RobocupClient() {
	delete client;
	delete brain;
}

/*************************************************************************
* Function name:	setRequest
* The Input:		string to be set as next request
* The Output:		-
* The Function operation:	if no request awaits - set the given one to
* 		be next
*************************************************************************/
void RobocupClient::setRequest(string request) {
	if (nextRequest.empty()) {
		nextRequest = request;
	}
}

/*************************************************************************
* Function name:	recieve
* The Input:		-
* The Output:		the recieved message
* The Function operation:	recieves a message from server and returns it
*************************************************************************/
string RobocupClient::recieve() {
	return client->recieveMsg();
}

/*************************************************************************
* Function name:	RobocupClient::send
* The Input:		-
* The Output:		true if command was sent, false if not
* The Function operation:	sends the message if we have one
*************************************************************************/
bool RobocupClient::send() {
	// If no request to make - return false
	if (nextRequest.empty()) {
		return false;
	}

	// Send request
	client->sendMsg(nextRequest);
	requests.push(nextRequest);

	// If player quit the game - terminate the thread
	if (player.hasExited()) {
		pthread_exit(NULL);
	}

	nextRequest.clear();
	return true;
}

/*************************************************************************
* Function name:	sendCommandsToServer
* The Input:		reference to current object (to overcome "static")
* The Output:		-
* The Function operation: sends generated requests to the server in
* 		intervals of REQ_INTERVAL.
*************************************************************************/
void RobocupClient::sendCommandsToServer(RobocupClient *thisRef) {
	while (true) {
		// Send request if we have one and sleep to avoid flooding the server
		if (thisRef->send()) {
			usleep(REQ_INTERVAL);
		}
	}
}

/*************************************************************************
* Function name:	recieveServerMessages
* The Input:		reference to current object (to overcome "static")
* The Output:		-
* The Function operation: get responses from server and parses them.
*************************************************************************/
void RobocupClient::recieveServerMessages(RobocupClient *thisRef) {
	while (true) {
		string message = thisRef->recieve(); // recieve response

		// Parse the message and update data
		PlayerBrain* brain = thisRef->getBrain();
		brain->setMsg(message);
		brain->think();

		// If the brain made request - save it
		if (brain->madeRequest()) {
			thisRef->setRequest(brain->getRequestToMake());
		}
	}
}

/*************************************************************************
* Function name:	startRequesting
* The Input:		-
* The Output:		-
* The Function operation: creates the requesting thread
*************************************************************************/
void RobocupClient::startRequesting() {
	pthread_create(&requesterThread, NULL, (void* (*)(void*)) &sendCommandsToServer, this);
}

/*************************************************************************
* Function name:	startRecieving
* The Input:		-
* The Output:		-
* The Function operation: creates the receving thread
*************************************************************************/
void RobocupClient::startRecieving() {
	pthread_create(&recieverThread, NULL, (void* (*)(void*)) &recieveServerMessages, this);
}

/*************************************************************************
* Function name:	joinReqesting
* The Input:		-
* The Output:		-
* The Function operation: waits until the requesting thread quits
*************************************************************************/
void RobocupClient::joinReqesting() {
	pthread_join(requesterThread, NULL);
}

/*************************************************************************
* Function name:	stopRecieving
* The Input:		-
* The Output:		-
* The Function operation: stops the receving thread
*************************************************************************/
void RobocupClient::stopRecieving() {
	pthread_cancel(recieverThread);
}
