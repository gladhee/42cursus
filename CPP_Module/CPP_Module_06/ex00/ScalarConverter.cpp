//
// Created by Heesung Choi on 11/13/24.
//

#include "ScalarConverter.hpp"
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <limits>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &other) {
	if (this != &other)
		*this = other;
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other) {
	if (this != &other)
		*this = other;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(std::string const &input) {
	if (isChar(input)) {
		convertChar(input);
	} else if (isInfOrNan(input)) {
		convertDouble(input);
	} else if (isInffOrNanf(input)) {
		convertFloat(input);
	} else if (isInteger(input)) {
		convertInt(input);
	} else if (isFloat(input)) {
		convertFloat(input);
	} else if (isDouble(input)) {
		convertDouble(input);
	} else {
		printImpossible();
	}
}

bool ScalarConverter::isChar(std::string const &input) {
	return input.length() == 1 && !std::isdigit(input[0]);
}

bool ScalarConverter::isInffOrNanf(std::string const &input) {
	std::string const infStrings[] = {"nanf", "+inff", "-inff", "inff"};

	for (size_t i = 0; i < 4; i++) {
		if (input == infStrings[i]) {
			return true;
		}
	}

	return (false);
}

bool ScalarConverter::isInfOrNan(std::string const &input) {
	std::string const infString[] = {"nan", "+inf", "-inf", "inf"};

	for (size_t i = 0; i < 4; i++) {
		if (input == infString[i]) {
			return true;
		}
	}

	return (false);
}

bool ScalarConverter::isInteger(std::string const &input) {
	size_t i = 0;

	if (input[i] == '+' || input[i] == '-')
		i++;

	if (input.length() - i > 10) {
		return false;
	}

	for (; i < input.length(); i++) {
		if (!std::isdigit(input[i])) {
			return false;
		}
	}

	return (true);
}

bool ScalarConverter::isFloat(std::string const &input) {
	if (input[input.length() - 1] != 'f') {
		return false;
	}

	size_t i = 0;

	if (input[i] == '+' || input[i] == '-')
		i++;

	for (; i < input.length() - 1; i++) {
		if (!std::isdigit(input[i]) && input[i] != '.') {
			return false;
		}
	}

	return (true);
}

bool ScalarConverter::isDouble(std::string const &input) {
	size_t i = 0;

	if (input[i] == '+' || input[i] == '-')
		i++;

	for (; i < input.length(); i++) {
		if (!std::isdigit(input[i]) && input[i] != '.')
			return (false);
	}

	return (true);
}

void ScalarConverter::convertChar(std::string const &input) {
	char c = input[0];

	printChar(c);
	printInt(static_cast<int>(c));
	printFloat(static_cast<float>(c));
	printDouble(static_cast<double>(c));
}

void ScalarConverter::convertInt(std::string const &input) {
	long long ll = std::strtol(input.c_str(), NULL, 10);

	if (isCharRange(ll))
		printChar(static_cast<char>(ll));
	else
		std::cout << "char: impossible" << std::endl;

	if (isIntRange(ll))
		printInt(static_cast<int>(ll));
	else
		std::cout << "int: impossible" << std::endl;

	printFloat(static_cast<float>(ll));
	printDouble(static_cast<double>(ll));
}

void ScalarConverter::convertFloat(std::string const &input) {
	float f = std::strtof(input.c_str(), NULL);

	if (isCharRange(f))
		printChar(static_cast<char>(f));
	else
		std::cout << "char: impossible" << std::endl;

	if (isIntRange(f))
		printInt(static_cast<int>(f));
	else
		std::cout << "int: impossible" << std::endl;

	printFloat(f);
	printDouble(static_cast<double>(f));
}

void ScalarConverter::convertDouble(std::string const &input) {
	double d = std::strtod(input.c_str(), NULL);

	if (isCharRange(d))
		printChar(static_cast<char>(d));
	else
		std::cout << "char: impossible" << std::endl;

	if (isIntRange(d))
		printInt(static_cast<int>(d));
	else
		std::cout << "int: impossible" << std::endl;

	printFloat(static_cast<float>(d));
	printDouble(d);
}

void ScalarConverter::printChar(char c) {
	std::cout << "char: ";

	if (std::isprint(c)) {
		std::cout << "'" << c << "'" << std::endl;
		return;
	}

	std::cout << "Non displayable" << std::endl;
}

void ScalarConverter::printInt(int i) {
	std::cout << "int: " << i << std::endl;
}

void ScalarConverter::printFloat(float f) {
	if (f == std::floor(f)) {
		std::cout << std::fixed << std::setprecision(1);
	}

	std::cout << "float: " << f << "f" << std::endl;
}

void ScalarConverter::printDouble(double d) {
	if (d == std::floor(d)) {
		std::cout << std::fixed << std::setprecision(1);
	}

	std::cout << "double: " << d << std::endl;
}

void ScalarConverter::printImpossible() {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}