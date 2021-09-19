/****************************************
* Student Name:		Rina Fridland & Shirly Bittan
* Exercise Name:	ex2 - sockets
* File description: UDP socket
****************************************/

#include "UdpSocket.h"

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <cstring>
#include <string>
#include <iostream>

#define BUFFER_SIZE 4096
#define ERR_SEND "\nNothing was sent\n"
#define ERR_RECIEVE "\nNothing was recieved\n"

using namespace std;

UdpSocket::UdpSocket() : ISocket(SOCK_DGRAM) {}
UdpSocket::~UdpSocket() {}

/*************************************************************************
* Function name:	sendTo
* The Input:		strMsg - message to send
* 					recieverInfo - the reciever address
* The Output:		-
* The Function operation: sends the message to the spec. address
*************************************************************************/
void UdpSocket::sendTo(string strMsg, struct sockaddr_in recieverInfo) {
	// Create char array to send
	char message[BUFFER_SIZE] = {0};
	strcpy(message, strMsg.c_str());
	int length = strlen(message) + 1;

	// Send the data and verify it's OK
	int sentBytes = sendto(sockDescr, message, length, 0,
			(struct sockaddr *) &recieverInfo, sizeof(recieverInfo));
	if (sentBytes < 0) {
		cout << ERR_SEND;
	}
}

/*************************************************************************
* Function name:	recieveFrom
* The Input:		a struct to be filled with address
* The Output:		the message recieved
* The Function operation: recieves a message into the buffer and saves address
*************************************************************************/
string UdpSocket::recieveFrom(struct sockaddr_in &senderInfo) {
	// Prepare the buffer for recieving
	char msg[BUFFER_SIZE] = {0};
	unsigned int infoLen = sizeof(struct sockaddr_in);

	// Recieve the message and check if it's ok
	int bytes = recvfrom(sockDescr, msg, BUFFER_SIZE, 0,
			(struct sockaddr *) &senderInfo, &infoLen);
	if (bytes < 0) {
		cout << ERR_RECIEVE;
	}

	// Return a string containing the message
	return string(msg);
}
