#include "Sed.hpp"

int main(int argc, char **argv) {
	if (argc != 4) {
		std::cout << "Usage: ./sed <filename> <string> <replace>" << std::endl;
		return (1);
	}
	try {
		Sed sed(argv[1], argv[2], argv[3]);
		sed.replace();
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
