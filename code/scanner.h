#ifndef SCANNER_H
#define SCANNER_H

#include <iostream>
#include <string>


class Scanner {
	public:
		const char* ip;
		SOCKET sockConnect, ListenSocket, AcceptSocket;

		void Scanner::socketCreation(const char* ip, int port);
		void Scanner::bindSocket(const char* ip, int port);
		void Scanner::listenForConnections(const char* ip, int port);
		void Scanner::connectToServer(const char* ip, int port);
		void Scanner::acceptConnections(const char* ip, int port);
		void Scanner::processData(const char* ip, int port);

	private:
		//will put smt here 
};


#endif
