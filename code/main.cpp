#include <iostream>
#include "scanner.h"

int main() {
	int port = 0;
	bool returnValue = false;

	std::cout << "Enter a port number: ";
	std::cin >> port;

	void bindSocket(const char* ip, int port);
	void listenForConnections(const char* ip, int port);
	void connectToServer(const char* ip, int port);
	void acceptConnections(const char* ip, int port);
	void processData(const char* ip, int port);

	std::cout << "Port" << "\t" << "State" << std::endl;
	std::cout << port << "\t" << (returnValue ? "OPEN" : "CLOSED") << std::endl;

	return 0;
}
