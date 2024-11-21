//
// Created by Heesung Choi on 11/19/24.
//

#ifndef CPP_MODULE_RPN_HPP
#define CPP_MODULE_RPN_HPP

#include <string>
#include <iostream>
#include <algorithm>
#include <stack>
#include <list>
#include <cctype>
#include <sstream>

class RPN {

private:
	std::stack <std::string> tokens;
	std::stack <std::string> operands;

	void processOperator(const std::string &token);

	static bool isNumber(const std::string &token);

	static std::string intToString(int value);

	static int stringToInt(const std::string &str);

	static std::list <std::string> split(const std::string &input, char delimiter);

	static void validateInput(const std::list <std::string> &tokens);

	static bool isValidToken(const std::string &token, const std::list <std::string> &operators);

	RPN();


public:
	RPN(const std::string &input);

	RPN(const RPN &other);

	RPN &operator=(const RPN &other);

	~RPN();

	std::string calculate();

};

#endif //CPP_MODULE_RPN_HPP
