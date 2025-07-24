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
		WSADATA wsaData;
		sockaddr_in service;

		void socketCreation(const char* ip, int port, bool& returnValue);
		void bindSocket(const char* ip, int port, bool& returnValue);
		void listenForConnections(const char* ip, int port, int& result, bool& returnValue);
		void connectToServer(const char* ip, int port, bool& returnValue);
		void acceptConnections(const char* ip, int port, bool& returnValue);
		void processData(const char* ip, int port, bool& returnValue);
};

#endif
