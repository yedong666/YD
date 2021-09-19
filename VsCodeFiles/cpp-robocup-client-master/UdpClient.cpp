/****************************************
* Student Name:		Rina Fridland & Shirly Bittan
* Exercise Name:	ex2 - sockets
* File description: UDP client socket
****************************************/

#include "UdpClient.h"
#include "UdpSocket.h"
#include <arpa/inet.h>
#include <cstring>
#include <string>

using namespace std;

/*************************************************************************
* Function name:	constructor
* The Input:		server's address and port
* The Output:		void
* The Function operation: sets the server address for first time request
*************************************************************************/
UdpClient::UdpClient(string strServerAddr, int portNum) : UdpSocket() {
	// Convert string to char array
	char serverAddr[BUFFER_SIZE];
	strcpy(serverAddr, strServerAddr.c_str());

	// Set the info
	setServerInfo(serverAddr, portNum);
}

UdpClient::~UdpClient() {}

/*************************************************************************
* Function name:	setServerInfo
* The Input:		server's address and port
* The Output:		void
* The Function operation: sets the server address for first time request
*************************************************************************/
void UdpClient::setServerInfo(char serverAddr[], int portNum) {
	memset(&serverInfo, 0, sizeof(serverInfo));
	serverInfo.sin_family = AF_INET;
	serverInfo.sin_addr.s_addr = inet_addr(serverAddr);
	serverInfo.sin_port = htons(portNum);
}

/*************************************************************************
* Function name:	sendMsg
* The Input:		message
* The Output:		void
* The Function operation: sends a message to the server
*************************************************************************/
void UdpClient::sendMsg(string msg) {
	UdpSocket::sendTo(msg, serverInfo);
}

/*************************************************************************
* Function name:	recieveMsg
* The Input:		void
* The Output:		message recieved
* The Function operation: recieves a message from the server
*************************************************************************/
string UdpClient::recieveMsg() {
	return UdpSocket::recieveFrom(serverInfo);
}
