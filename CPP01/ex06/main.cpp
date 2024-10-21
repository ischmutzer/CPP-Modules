#include "Harl.hpp"
#include <iostream>
#include <string>

int	checkLevel(std::string level) {
	std::string	existingLevels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++) {
		if (level == existingLevels[i])
			return i;
	}
	return -1;
}

int	main(int argc, char** argv) {
	if (argc == 2) {
		Harl	obj;
		int level = checkLevel(argv[1]);

		switch (level) {
			case 0:
				std::cout << "[DEBUG]" << std::endl;
				obj.complain("debug");
				std::cout << "\n" << std::endl;

			case 1:
				std::cout << "[INFO]" << std::endl;
				obj.complain("info");
				std::cout << "\n" << std::endl;
			
			case 2:
				std::cout << "[WARNING]" << std::endl;
				obj.complain("warning");
				std::cout << "\n" << std::endl;

			case 3:
				std::cout << "[ERROR]" << std::endl;
				obj.complain("error");
				break ;
			
			default:
				std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		}
		return 0;
	}
	std::cout << "Error: argument missing" << std::endl;
	return 1;
}
