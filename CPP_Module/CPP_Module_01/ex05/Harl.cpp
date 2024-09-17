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

int Harl::getHashLevel(const std::string &level) const {
	for (int i = 0; i < 4; i++) {
		if (level == std::string(LEVELS[i]))
			return i;
	}
}

void (Harl::*Harl::getComplain(const std::string &level)) () {
	switch (getLevel(level)) {
		case DEBUG_N:
			return &Harl::debug;
		case INFO_N:
			return &Harl::info;
		case WARNING_N:
			return &Harl::warning;
		case ERROR_N:
			return &Harl::error;
		default:
			throw std::invalid_argument("Invalid level");
	}
}