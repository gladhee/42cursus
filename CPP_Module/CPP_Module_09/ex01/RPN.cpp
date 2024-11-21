//
// Created by Heesung Choi on 11/19/24.
//

#include "RPN.hpp"

typedef std::list<std::string>::const_reverse_iterator const_reverse_iterator;
typedef std::list<std::string>::const_iterator const_iterator;

RPN::RPN() {}

RPN::RPN(const std::string &input) {
	std::list <std::string> splittedInput = split(input, ' ');

	validateInput(splittedInput);

	for (const_reverse_iterator it = splittedInput.rbegin(); it != splittedInput.rend(); ++it) {
		tokens.push(*it);
	}
}

RPN::RPN(const RPN &other) {
	if (this == &other) {
		return;
	}

	tokens = other.tokens;
	operands = other.operands;
}

RPN &RPN::operator=(const RPN &other) {
	if (this == &other)
		return *this;

	tokens = other.tokens;
	operands = other.operands;

	return *this;
}

RPN::~RPN() {}

std::string RPN::calculate() {
	while (!tokens.empty()) {
		std::string token = tokens.top();
		tokens.pop();

		if (isNumber(token)) {
			operands.push(token);
		} else {
			processOperator(token);
		}
	}

	if (operands.size() != 1) {
		throw std::invalid_argument("Invalid input: multiple or no results left in stack.");
	}

	return operands.top();
}

void RPN::processOperator(const std::string& token) {
	if (operands.size() < 2) {
		throw std::invalid_argument("Invalid input: not enough operands for operation.");
	}

	int operand1 = stringToInt(operands.top());
	operands.pop();
	int operand2 = stringToInt(operands.top());
	operands.pop();

	int result;
	if (token == "+") {
		checkAdditionOverflow(operand2, operand1);
		result = operand2 + operand1;
	} else if (token == "-") {
		checkSubtractionOverflow(operand2, operand1);
		result = operand2 - operand1;
	} else if (token == "*") {
		checkMultiplicationOverflow(operand2, operand1);
		result = operand2 * operand1;
	} else if (token == "/") {
		if (operand1 == 0) {
			throw std::invalid_argument("Division by zero is not allowed.");
		}
		result = operand2 / operand1;
	} else {
		throw std::invalid_argument("Invalid operator: " + token);
	}

	operands.push(intToString(result));
}

bool RPN::isNumber(const std::string &token) {
	return !token.empty() && std::isdigit(token[0]);
}

std::string RPN::intToString(int value) {
	std::ostringstream oss;
	oss << value;
	return oss.str();
}

int RPN::stringToInt(const std::string &str) {
	std::istringstream iss(str);
	int value;
	if (!(iss >> value)) {
		throw std::invalid_argument("Invalid number: " + str);
	}
	return value;
}

void RPN::checkAdditionOverflow(int a, int b) {
	if ((b > 0 && a > INT_MAX - b) || (b < 0 && a < INT_MIN - b)) {
		throw std::overflow_error("Addition overflow: " + intToString(a) + " + " + intToString(b));
	}
}

void RPN::checkSubtractionOverflow(int a, int b) {
	if ((b < 0 && a > INT_MAX + b) || (b > 0 && a < INT_MIN + b)) {
		throw std::overflow_error("Subtraction overflow: " + intToString(a) + " - " + intToString(b));
	}
}

void RPN::checkMultiplicationOverflow(int a, int b) {
	if (a > 0 && b > 0 && a > INT_MAX / b) {
		throw std::overflow_error("Multiplication overflow: " + intToString(a) + " * " + intToString(b));
	}
	if (a > 0 && b < 0 && b < INT_MIN / a) {
		throw std::overflow_error("Multiplication overflow: " + intToString(a) + " * " + intToString(b));
	}
	if (a < 0 && b > 0 && a < INT_MIN / b) {
		throw std::overflow_error("Multiplication overflow: " + intToString(a) + " * " + intToString(b));
	}
	if (a < 0 && b < 0 && a < INT_MAX / b) {
		throw std::overflow_error("Multiplication overflow: " + intToString(a) + " * " + intToString(b));
	}
}

std::list <std::string> RPN::split(const std::string &input, char delimiter) {
	std::list <std::string> result;
	std::istringstream iss(input);
	std::string token;

	while (std::getline(iss, token, delimiter)) {
		result.push_back(token);
	}

	return result;
}

void RPN::validateInput(const std::list <std::string> &tokens) {
	std::list <std::string> defaultOperators;
	defaultOperators.push_back("+");
	defaultOperators.push_back("-");
	defaultOperators.push_back("*");
	defaultOperators.push_back("/");

	if (tokens.empty()) {
		throw std::invalid_argument("Empty input");
	}

	for (const_iterator it = tokens.begin(); it != tokens.end(); ++it) {
		if (!isValidToken(*it, defaultOperators)) {
			throw std::invalid_argument("Invalid input: " + *it);
		}
	}
}

bool RPN::isValidToken(const std::string &token, const std::list <std::string> &operators) {
	if (token.length() == 1 && std::isdigit(token[0])) {
		return true;
	}
	if (std::find(operators.begin(), operators.end(), token) != operators.end()) {
		return true;
	}

	return false;
}
