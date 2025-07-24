#include "scanner.h"
#include <iostream>
#include <string>

#include <winsock2.h>
#include <ws2tcpip.h>

#define DEFAULT_BUFLEN 512

//Used: https://learn.microsoft.com/en-us/windows/win32/api/winsock2/

void Scanner::socketCreation(const char* ip, int port, bool& returnValue) {
	int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (result != 0) { 
		std::cout << "Cant find usable Winsock.dll (Dynamic Link Library)";
		WSACleanup();
		returnValue = false; 
	}
	//socket - Creating  actual socket (TCP/UDP), using IPv4
	sockConnect = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); 
	if (sockConnect == INVALID_SOCKET) {
		std::cout << "Socket creation failed with error" << std::endl;
		WSACleanup();
		returnValue = false;
		return;
	}
	returnValue = true;

}

//Initiates connection to remote server
void Scanner::connectToServer(const char* ip, int port, bool& returnValue) {
	service.sin_family = AF_INET;
	inet_pton(AF_INET, ip, &service.sin_addr);
	service.sin_port = htons(port);

	int connectResult = connect(sockConnect, (SOCKADDR*)&service, sizeof(service));
	if (connectResult == SOCKET_ERROR) {
		std::cout << "The connecting result failed with an error." << std::endl;
		WSACleanup();
		returnValue = false;
		return; //signals to exit
	}

	std::cout << "Connected to server..";
	returnValue = true;
	
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
		std::cout << "The send failed with an error." << std::endl;
		WSACleanup();
		returnValue = false;
		return;
	}
	do {
		dataSending = recv(sockConnect, recvbuf, recvbuflen, 0);
		if (dataSending > 0) {
			std::cout << "Data (bytes) are received";
		}
		else if (dataSending == 0) {
			std::cout << "Connection closed";
			break;
		}
		else {
			std::cout << "Failed with error";
			break;
		}
	} while (dataSending > 0);

	closesocket(sockConnect);
	WSACleanup();
	returnValue = true;
}
