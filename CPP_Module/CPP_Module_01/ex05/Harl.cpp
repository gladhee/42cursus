#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug() {
	std::cout << HARL_DEBUG << std::endl;
}

void Harl::info() {
	std::cout << HARL_INFO << std::endl;
}

void Harl::warning() {
	std::cout << HARL_WARNING << std::endl;
}

void Harl::error() {
	std::cout << HARL_ERROR << std::endl;
}

void Harl::complain(std::string level) {
	(this->*getComplain(level))();
}

size_t Harl::getHashLevel(const std::string &level) const {
	unsigned int i = 0;
	unsigned int hash = 0;

	while (i < level.length()) {
		hash = level[i] + (hash << 6) + (hash << 16) - hash;
		i++;
	}

	return (hash);
}

void (Harl::*Harl::getComplain(const std::string &level)) () {
	switch (getHashLevel(level)) {
		case DEBUG_H:
			return &Harl::debug;
		case INFO_H:
			return &Harl::info;
		case WARNING_H:
			return &Harl::warning;
		case ERROR_H:
			return &Harl::error;
		default:
			throw std::invalid_argument("Invalid level");
	}
}
