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

void (Harl::*Harl::getComplain(const std::string &level)) () const {
	switch (level) {
		case DEBUG:
			return &Harl::debug;
		case INFO:
			return &Harl::info;
		case WARNING:
			return &Harl::warning;
		case ERROR:
			return &Harl::error;
		default:
			throw std::invalid_argument("Invalid level");
	}
}