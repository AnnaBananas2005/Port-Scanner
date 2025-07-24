#include <iostream>
#include "scanner.h"

int main() {
	int port = 0;
	const char* ip = "127.0.0.1";
	bool returnValue = false;

	std::cout << "Enter a port number: ";
	std::cin >> port;

	Scanner scanner;
	scanner.socketCreation(ip, port, returnValue);
	if (returnValue) {
		scanner.connectToServer(ip, port, returnValue);
	}

	std::cout << "Port" << "\t" << "State" << std::endl;
	std::cout << port << "\t" << (returnValue ? "OPEN" : "CLOSED") << std::endl;

	return 0;
}
