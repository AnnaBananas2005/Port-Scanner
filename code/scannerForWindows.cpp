#include "scanner.h"
#include <iostream>
#include <string>

#include <winsock2.h>
#include <ws2tcpip.h>

#define DEFAULT_BUFLEN 512

//Used: https://learn.microsoft.com/en-us/windows/win32/api/winsock2/

const char* ip = "127.0.0.1";

void Scanner::socketCreation(const char* ip, int port, bool& returnValue) {
	int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (result != 0) { 
		std::cout << "Cant find usable Winsock.dll (Dynamic Link Library)";
		WSACleanup();
		returnValue = false;
	}
	sockConnect = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); 
}

//Associates socket with local ip address & port
void Scanner::bindSocket(const char* ip, int port, bool& returnValue){
	int storeResult = 0;

	ListenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);	
	sockaddr_in service; 
	service.sin_family = AF_INET;

	inet_pton(AF_INET, ip, &service.sin_addr);	
	service.sin_port = htons(port);

	storeResult = bind(ListenSocket, (SOCKADDR*)&service, sizeof(service));
	if (storeResult == SOCKET_ERROR) {
		std::cout << "The bind has failed with an error.";
		WSACleanup();
		returnValue = false;
	}
}

//Ready to accept connections
void Scanner::listenForConnections(const char* ip, int port, int &result, bool& returnValue) {

	if (listen(ListenSocket, SOMAXCONN) == SOCKET_ERROR) {
		std::cout << "Listen socket failed with an error";
		WSACleanup();
		returnValue = false; 
	}
	std::cout << "Listening on socket..";
	result = closesocket(ListenSocket);

	if (result == SOCKET_ERROR) {
		std::cout << "The listen socket result failed with an error.";
		WSACleanup();
		returnValue = false;
	}
	else {
		std::cout << "Connection successful" << std::endl;
		returnValue = true;	
	}

}

//Initiates connection to remote server
void Scanner::connectToServer(const char* ip, int port, bool& returnValue) {
	service.sin_family = AF_INET;
	inet_pton(AF_INET, ip, &service.sin_addr);
	service.sin_port = htons(port);

	int connectResult = connect(sockConnect, (SOCKADDR*)&service, sizeof(service));
	if (connectResult == SOCKET_ERROR) {
		std::cout << "The connecting result failed with an error.";
		WSACleanup();
		returnValue = false;
	}

	std::cout << "Connecting to server..";
	connectResult = closesocket(sockConnect);

	if (connectResult == SOCKET_ERROR) {
		std::cout << "The connect result failed with an error.";
		WSACleanup();
		returnValue = false;
	}
}

// Accepts connections from client
void Scanner::acceptConnections(const char* ip, int port, bool& returnValue) {
	AcceptSocket = accept(ListenSocket, NULL, NULL);
	if (AcceptSocket == SOCKET_ERROR) {
		std::cout << "The accept socket failed with an error.";
		WSACleanup();
		returnValue = false;
	}
	closesocket(ListenSocket);
}

//Data exchange via connected socket 
void Scanner::processData(const char* ip, int port, bool& returnValue) {
	int dataSending = 0;
	int recvbuflen = DEFAULT_BUFLEN;

	const char* sendbuf = "The client is sending data test";
	char recvbuf[512]; //512 is the DEFAULT_BUFLEN

	//This part is a handshake (confirming communication)
	int sendFirstBuffer = send(sockConnect, sendbuf, (int)strlen(sendbuf), 0);
	if (sendFirstBuffer == SOCKET_ERROR) {
		std::cout << "The send failed with an error.";
		WSACleanup();
		returnValue = false;
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

