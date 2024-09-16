#include "PhoneBook.hpp"
#include <cstdio>

int main(void)
{
	PhoneBook phoneBook;
	std::string cmd;

	while (true) {
		try {
			std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;
			std::cout << "Enter a command: ";
			std::getline(std::cin, cmd);
			if (cmd == "ADD") {
				phoneBook.addContact();
			}
			else if (cmd == "SEARCH") {
				phoneBook.searchContact();
			}
			else if (cmd == "EXIT") {
				std::cout << "Exiting the program..." << std::endl;
				break ;
			}
			else if (std::cin.eof())
				throw std::exception();
			else
				std::cout << "Invalid command. Please try again." << std::endl;
		} catch (std::exception &e) {
			std::cin.clear();
			clearerr(stdin);
			std::cout << std::endl;
		}
	}
	return (EXIT_SUCCESS);
}