//
// Created by Heesung Choi on 11/13/24.
//

#ifndef CPP_MODULE_SCALARCONVERTER_HPP
#define CPP_MODULE_SCALARCONVERTER_HPP

#include <iostream>
#include <limits>

class ScalarConverter {

private:
	ScalarConverter();

	ScalarConverter(ScalarConverter const &copy);

	ScalarConverter &operator=(ScalarConverter const &copy);

	static bool isChar(std::string const &input);

	static bool isInfOrNan(std::string const &input);

	static bool isInffOrNanf(std::string const &input);

	static bool isInteger(std::string const &input);

	static bool isFloat(std::string const &input);

	static bool isDouble(std::string const &input);

	static void convertChar(std::string const &input);

	static void convertInt(std::string const &input);

	static void convertFloat(std::string const &input);

	static void convertDouble(std::string const &input);

	static void printChar(char input);

	static void printInt(int input);

	static void printFloat(float input);

	static void printDouble(double input);

	static void printImpossible();

	template<typename T>
	static bool isCharRange(T input) {
		if (std::numeric_limits<char>::min() <= input &&
			input <= std::numeric_limits<char>::max()) {
			return true;
		}
		return false;
	}

	template<typename T>
	static bool isIntRange(T input) {
		if (std::numeric_limits<int>::min() <= input &&
			input <= std::numeric_limits<int>::max()) {
			return true;
		}
		return false;
	}


public:
	~ScalarConverter();

	static void convert(std::string const &input);

};


#endif //CPP_MODULE_SCALARCONVERTER_HPP
