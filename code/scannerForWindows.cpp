#include "scanner.h"
#include <iostream>
#include <string>

#include <winsock2.h>
#include <ws2tcpip.h>

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
