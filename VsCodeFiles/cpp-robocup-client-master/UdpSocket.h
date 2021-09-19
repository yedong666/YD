/****************************************
* Student Name:		Rina Fridland & Shirly Bittan
* Exercise Name:	ex2 - sockets
* File description: UDP socket
****************************************/

#ifndef UDPSOCKET_H_
#define UDPSOCKET_H_

#include "ISocket.h"
#include <string>
using namespace std;

class UdpSocket: public ISocket {
protected:
	void sendTo(string, struct sockaddr_in); // send message
	string recieveFrom(struct sockaddr_in&); // recieve message and sender address

public:
	UdpSocket();
	virtual ~UdpSocket();

	virtual void sendMsg(string) = 0;
	virtual string recieveMsg() = 0;
};

#endif /* UDPSOCKET_H_ */
