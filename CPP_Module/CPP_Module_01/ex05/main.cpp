#include "Harl.hpp"

int main() {
	Harl harl;

	try {
		std::cout << "Harl complains:" << std::endl;
		std::cout << "[ DEBUG ]" << std::endl;
		harl.complain("DEBUG");

		std::cout << std::endl;
		std::cout << "[ INFO ]" << std::endl;
		harl.complain("INFO");

		std::cout << std::endl;
		std::cout << "[ WARNING ]" << std::endl;
		harl.complain("WARNING");

		std::cout << std::endl;
		std::cout << "[ ERROR ]" << std::endl;
		harl.complain("ERROR");
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}