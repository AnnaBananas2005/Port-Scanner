#include "scanner.h"
#include <iostream>
#include <string>

#include <winsock2.h>
#include <ws2tcpip.h>

//Used: https://learn.microsoft.com/en-us/windows/win32/api/winsock2/

const char* ip = "127.0.0.1";

void Scanner::socketCreation(const char* ip, int port) {
	//initializes winsock
	int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (result != 0) { 
		std::cout << "Cant find usable Winsock.dll (Dynamic Link Library)";
		WSACleanup();
		return 1;
	}
	//socket - Creating  actual socket (TCP/UDP), using IPv4
	sockConnect = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); //(Could also replace IPPROTO_TCP with 6)

}

//Associates socket with local ip address & port
void Scanner::bindSocket(const char* ip, int port){
	int returnValue = 0;

	ListenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);	//Can't you just replace this part with sock? From socketCreation
	sockaddr_in service; //the socket address that gets used to bind
	service.sin_family = AF_INET;
	inet_pton(AF_INET, ip, &serverAddress.sin_addr);
	service.sin_port = htons(/*port we returned from*/); //mb we write an if, if its a port-range?

	returnValue = bind(ListenSocket, (SOCKADDR*)&service, sizeof(service);
	if (returnValue == SOCKET_ERROR) {
		std::cout << "The bind has failed with an error.";
		WSACleanup();
		return 1;
	}
}

//Ready to accept connections
void Scanner::listenForConnections(const char* ip, int port) {
	int listenSocketResult = 0;

	if (listen(ListenSocket, SOMAXCONN) == SOCKET_ERROR) {
		std::cout << "Listen socket failed with an error";
		WSACleanup();
		return 1;
	}
	std::cout << "Listening on socket..";
	listenSocketResult = closesocket(ListenSocket);

	if (listenSocketResult == SOCKET_ERROR) {
		std::cout << "The listen socket result failed with an error.";
		WSACleanup();
		return 1;
	}

}

//connect (client) - Initiates connection to remote server

void Scanner::connectToServer(const char* ip, int port) {
	int connectResult = connect(sockConnect/*from socketCreation*/, (SOCKADDR*)&service /*from bindSocket*/, sizeof(service));
	if (connectResult == SOCKET_ERROR) {
		std::cout << "The connecting result failed with an error.";
		WSACleanup();
		return 1;
	}

	std::cout << "Connecting to server..";
	connectResult = closesocket(sockConnect);

	if (connectResult == SOCKET_ERROR) {
		std::cout << "The connect result failed with an error.";
		WSACleanup();
		return 1;
	}
}

//accept (server) - Accepts connections from client

void Scanner::acceptConnections(const char* ip, int port) {
	AcceptSocket = accept(ListenSocket, NULL, NULL);
	if (AcceptSocket == SOCKET_ERROR) {
		std::cout << "The accept socket failed with an error.";
		WSACleanup();
		return 1;
	}
	closesocket(ListenSocket);
}

//send & recv - Data exchange via connected socket (could possibly be seperated)
void Scanner::processData(const char* ip, int port) {
	int dataSending = 0;
	char* sendbuf = "The client is sending data test";
	//This part is a handshake (confirming communication)
	int sendFirstBuffer = send(sockConnect, sendbuf, (int)strlen(sendbuf), 0);
	if (sendFirstBuffer == SOCKET_ERROR) {
		std::cout << "The send failed with an error.";
		WSACleanup();
		return 1;
	}
	do {
		dataSending = recv(sockConnect, recvbuf, recvbuflen, 0);
		if (dataSending > 0) {
			std::cout << "Data (bytes) are received";
		}
		else if (dataSending == 0) {
			std::cout << "Connection closed";
		}
		else {
			std::cout << "Failed with error";
		}
	} while (dataSending > 0);

	closesocket(sockConnect);
	WSACleanup();
}





