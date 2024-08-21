#include <iostream>
#include <cstdlib>
#include "PhoneBook.hpp"

int	main() {
	PhoneBook phonebook;
	std::strign cmd;

	whlie (true) {
		try {
			std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;
			std::cout << "Enter a command: ";
			std::cin >> cmd;
			if (cmd == "ADD") {
				phonebook.addContact();
			}
			else if (cmd == "SEARCH") {
				phonebook.
			}
			else if (cmd == "EXIT") {
				std::cout << "Exiting the program..." << std::endl;
				break ;
			}
			else if (std::cin.eof()) {
				std::cout << "Exiting the program..." << std::endl;
				break ;
			}
			else
				std::cout << "Invalid command. Please try again." << std::endl;
		} catch (std::exception &e) {
			std::cin.clear();
			clearerr(stdin);
			std::cout << std::endl
		}
	}
	return (EXIT_SUCCESS);
}
