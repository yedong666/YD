/****************************************
* Student Name:		Rina Fridland & Shirly Bittan
* Exercise Name:	ex2 - sockets
* File description:	any socket interface
****************************************/

#include "ISocket.h"

#include <unistd.h>
#include <cstdlib>
#include <iostream>

using namespace std;

#define ERROR_CREATE_SOCKET "Problem creating socket"

// constructor - create socket by protocol - TCP or UDP
ISocket::ISocket(__socket_type type) {
	sockDescr = socket(AF_INET, type, 0);
	if (sockDescr < 0) {
		cout << ERROR_CREATE_SOCKET;
		exit(1);
	}
}

ISocket::ISocket(int sockDescr) {
	this->sockDescr = sockDescr;
}

ISocket::~ISocket() {
	close(sockDescr);
}
