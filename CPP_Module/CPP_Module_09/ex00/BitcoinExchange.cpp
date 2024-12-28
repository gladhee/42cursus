//
// Created by Heesung Choi on 11/19/24.
//

#include "BitcoinExchange.hpp"

const std::string BitcoinExchange::DATABASE_FILE = "data.csv";
const std::string BitcoinExchange::DATABASE_KEY = "date";
const std::string BitcoinExchange::DATABASE_VALUE = "exchange_rate";
const char BitcoinExchange::DATABASE_DELIMITER = ',';
const std::string BitcoinExchange::INPUT_KEY = "date";
const std::string BitcoinExchange::INPUT_VALUE = "value";
const char BitcoinExchange::INPUT_DELIMITER = '|';
const int BitcoinExchange::DATE_LENGTH = 10;
const char BitcoinExchange::DATE_DELIMITER = '-';

BitcoinExchange::BitcoinExchange() {
	this->exchangeRates = loadExchangeRate(DATABASE_FILE);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
	if (this == &other) {
		return;
	}

	exchangeRates = other.exchangeRates;
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this == &other) {
		return *this;
	}

	exchangeRates = other.exchangeRates;

	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

std::map<std::string, double> BitcoinExchange::loadExchangeRate(const std::string &filename) {
	std::map<std::string, double> exchangeRates;

	std::ifstream database = getFile(filename);
	skipHeader(database);
	exchangeRates = processLine(database);
	database.close();

	return exchangeRates;
}

void BitcoinExchange::skipHeader(std::ifstream &database) {
	std::string line;
	std::getline(database, line);
}

std::map<std::string, double> BitcoinExchange::processLine(std::ifstream &database) {
	std::map<std::string, double> exchangeRates;
	std::string line, key, value;
	double rate;

	while (std::getline(database, line)) {
		std::istringstream iss(line);

		std::getline(iss, key, DATABASE_DELIMITER);
		std::getline(iss, value, DATABASE_DELIMITER);

		rate = stringToDouble(value);
		exchangeRates[key] = rate;
	}

	return exchangeRates;
}

void BitcoinExchange::validateInputHeader(std::ifstream &inputFile) {
	std::string line, key, value;
	char dlm;
	std::stringstream ss;

	if (!std::getline(inputFile, line)) {
		throw std::runtime_error("Input file is empty.");
	}

	ss << line;
	ss >> key >> dlm >> value;

	if (key != INPUT_KEY || dlm != INPUT_DELIMITER || value != INPUT_VALUE) {
		throw std::runtime_error("Invalid input file header.");
	}
}

void BitcoinExchange::processLine(std::string &line) {
	std::string key, value;
	char dlm;
	std::istringstream ss(line);

	ss >> key >> dlm >> value;

	if (dlm != INPUT_DELIMITER) {
		throw std::invalid_argument("bad input => " + line);
	}

	validateDate(key);
	double quantity = stringToDouble(value);
	validateQuantity(quantity);

	double result = calculate(key, quantity);

	std::cout << key << " => " << quantity << " = " << result << std::endl;
}

void BitcoinExchange::validateDate(const std::string &date) {
	if (date.length() != DATE_LENGTH) {
		throw std::invalid_argument("bad input => " + date);
	}

	int year, month, day;
	char dlm1, dlm2;
	std::stringstream ss;

	ss << date;
	ss >> year >> dlm1 >> month >> dlm2 >> day;

	if (ss.fail() || dlm1 != DATE_DELIMITER || dlm2 != DATE_DELIMITER || !isValidDate(year, month, day)) {
		throw std::invalid_argument("bad input => " + date);
	}
}

bool BitcoinExchange::isValidDate(int year, int month, int day) {
	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (isLeapYear(year)) {
		daysInMonth[1] = 29;
	}

	if (month < 1 || month > 12) {
		return false;
	}

	if (day < 1 || day > daysInMonth[month - 1]) {
		return false;
	}
	return true;
}

bool BitcoinExchange::isLeapYear(int year) {
	if (year % 4 == 0) {
		if (year % 100 == 0) {
			return year % 400 == 0;
		}
		return true;
	}
	return false;
}

void BitcoinExchange::validateQuantity(double quantity) {
	if (quantity < 0) {
		throw std::invalid_argument("not a positive number.");
	}

	if (quantity > 1000) {
		throw std::invalid_argument("too large number.");
	}
}

double BitcoinExchange::stringToDouble(const std::string &str) {
	std::istringstream iss(str);
	double value;

	if (!(iss >> value)) {
		throw std::invalid_argument("not a positive number.");
	}

	return value;
}

double BitcoinExchange::calculate(const std::string &date, double quantity) {
	std::map<std::string, double>::iterator it = exchangeRates.find(date);

	if (it == exchangeRates.end()) {
		it = exchangeRates.lower_bound(date);
		if (it == exchangeRates.begin()) {
			throw std::runtime_error("No exchange rate found for date: " + date);
		}
		--it;
	}

	return it->second * quantity;
}

std::ifstream BitcoinExchange::getFile(const std::string &filename) {
	std::ifstream file(filename.c_str());

	if (!file.is_open()) {
		throw std::runtime_error("Cannot open file: " + filename);
	}

	return file;
}
