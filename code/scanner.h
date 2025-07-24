#ifndef SCANNER_H
#define SCANNER_H
#include <iostream>
#include <string>

#include <winsock2.h>
#include <ws2tcpip.h>

class Scanner {
	public:
		const char* ip;
		SOCKET sockConnect, ListenSocket, AcceptSocket;

		void socketCreation(const char* ip, int port);
		void bindSocket(const char* ip, int port);
		void listenForConnections(const char* ip, int port);
		void connectToServer(const char* ip, int port);
		void acceptConnections(const char* ip, int port);
		void processData(const char* ip, int port);

	private:
		//deciding what to put
};


#endif
