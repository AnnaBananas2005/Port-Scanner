#include <iostream>
#include <iomanip> //for setw

#include "scanner.h"

int main() {
	int port = 0;
	std::cout << "Enter a port number: ";
	std::cin >> port;
	void bindSocket(const char* ip, int port);
	void listenForConnections(const char* ip, int port);
	void connectToServer(const char* ip, int port);
	void acceptConnections(const char* ip, int port);
	void processData(const char* ip, int port);

	std::cout << "Port" << std::setw(5) << "State";
	std::cout << port;  //will add returned state

	return 0;
}
