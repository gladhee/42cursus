//
// Created by Heesung Choi on 11/13/24.
//

#ifndef CPP_MODULE_SCALARCONVERTER_HPP
#define CPP_MODULE_SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter {

private:
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);

	static bool isChar(const std::string &str);
	static bool isInt(const std::string &str);
	static bool isFloat(const std::string &str);
	static bool isDouble(const std::string &str);

	static char convertToChar(const std::string &str);
	static int convertToInt(const std::string &str);
	static float convertToFloat(const std::string &str);
	static double convertToDouble(const std::string &str);

	static void printError();

	static void printChar(char c);
	static void printInt(int i);
	static void printFloat(float f);
	static void printDouble(double d);


public:
	static void convert(const std::string &input);

};


#endif //CPP_MODULE_SCALARCONVERTER_HPP
