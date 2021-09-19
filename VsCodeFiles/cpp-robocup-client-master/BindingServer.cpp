/****************************************
* Student Name:		Rina Fridland & Shirly Bittan
* Exercise Name:	ex2 - sockets
* File description: Server binder class.
****************************************/

#include "BindingServer.h"

#include <netinet/in.h>
#include <sys/socket.h>
#include <cstdlib>
#include <cstring>
#include <iostream>

#define ERROR_MSG "\nProblem binding server\n"

using namespace std;

/*************************************************************************
* Function name:	bindServer
* The Input:		sockDescr - server's socket description code
* 					port - the port to bind to
* The Output:		-
* The Function operation: binds the given server
*************************************************************************/
void BindingServer::bindServer(int sockDescr, int port) {
	// Set the binding info
	struct sockaddr_in addrInfo;
	memset(&addrInfo, 0, sizeof(addrInfo));
	addrInfo.sin_family = AF_INET;
	addrInfo.sin_addr.s_addr = INADDR_ANY;
	addrInfo.sin_port = htons(port);

	// Bind the server
	if (bind(sockDescr, (struct sockaddr *) &addrInfo, sizeof(addrInfo)) < 0) {
		cout << ERROR_MSG;
		exit(1);
	}
}
