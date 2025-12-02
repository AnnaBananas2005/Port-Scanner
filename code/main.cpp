#include <iostream>
#include "scanner.h"

int main() {
	int port = 0;
	int startRange = 0; 
	int endRange = 0;
	const char* ip = "127.0.0.1";
	bool returnValue = false;

	std::string choose = "";
	std::cout << "Would you like to scan one port or a range? ('one' or 'range'): ";
	std::cin >> choose;

	Scanner scanner;
	if (choose == "one" || choose == "One") {
		std::cout << "Enter a port number: ";
		std::cin >> port;

		scanner.socketCreation(ip, port, returnValue);
		if (returnValue) {
			scanner.connectToServer(ip, port, returnValue);
		}

		std::cout << "Port" << "\t" << "State" << std::endl;
		std::cout << port << "\t" << (returnValue ? "OPEN" : "CLOSED") << std::endl;

	}

	else if (choose == "range" || choose == "Range") {
		std::cout << "Enter a range" << std::endl;
		std::cout << "1: ";
		std::cin >> startRange;
		std::cout << "2: ";
		std::cin >> endRange;

		scanner.rangeScan(scanner, ip, startRange, endRange);
	}

	return 0;
}
