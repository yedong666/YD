/****************************************
* Student Name:		Rina Fridland & Shirly Bittan
* Exercise Name:	ex2 - sockets
* File description:	any socket interface
****************************************/

#ifndef ISOCKET_H_
#define ISOCKET_H_

#include <sys/socket.h>
#include <string>
#define BUFFER_SIZE 4096

using namespace std;

class ISocket {
protected:
	int sockDescr;

public:
	ISocket(int);
	ISocket(__socket_type);
	virtual ~ISocket();

	virtual void sendMsg(string) = 0;
	virtual string recieveMsg() = 0;

	int getSockDescr() const {
		return sockDescr;
	}
};

#endif
