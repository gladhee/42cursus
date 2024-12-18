//
// Created by Heesung Choi on 11/13/24.
//

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
	(void)other;
	return *this;
}

bool ScalarConverter::isChar(const std::string &str) {
	if (str.length() == 1 && !std::isdigit(str[0])) {
		return true;
	}
	return false;
}

bool ScalarConverter::isInt(const std::string &str) {
	if ()

}