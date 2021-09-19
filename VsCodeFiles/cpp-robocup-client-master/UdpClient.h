/****************************************
* Student Name:		Rina Fridland & Shirly Bittan
* Exercise Name:	ex2 - sockets
* File description: UDP client socket
****************************************/

#ifndef UDPCLIENT_H_
#define UDPCLIENT_H_

#include "UdpSocket.h"
#include <string>
#include <arpa/inet.h>

using namespace std;

class UdpClient: public UdpSocket {
private:
	struct sockaddr_in serverInfo;
	void setServerInfo(char[], int);

public:
	UdpClient(string, int);
	virtual ~UdpClient();

	void sendMsg(string); // send message to server
	string recieveMsg(); // recieve message from server
};

#endif /* UDPCLIENT_H_ */
