//
// Created by Heesung Choi on 11/19/24.
//

#ifndef CPP_MODULE_BITCOINEXCHANGE_HPP
#define CPP_MODULE_BITCOINEXCHANGE_HPP

#include <string>
#include <algorithm>
#include <map>
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <exception>
#include <sstream>
#include <ctime>

class BitcoinExchange {

	static const std::string DATABASE_FILE;
	static const std::string DATABASE_KEY;
	static const std::string DATABASE_VALUE;
	static const char DATABASE_DELIMITER;
	static const std::string INPUT_KEY;
	static const std::string INPUT_VALUE;
	static const char INPUT_DELIMITER;
	static const int DATE_LENGTH;
	static const char DATE_DELIMITER;

private:
	std::map<std::string, double> exchangeRates;


	BitcoinExchange(const BitcoinExchange &other);

	BitcoinExchange &operator=(const BitcoinExchange &other);

	std::map<std::string, double> loadExchangeRate(const std::string &filename);

	void skipHeader(std::ifstream *database);

	std::map<std::string, double> processLine(std::ifstream *database);

	void validateDate(const std::string &date);

	bool isValidDate(int year, int month, int day);

	void validateQuantity(double quantity);

	double calculate(const std::string &date, double quantity);

	double stringToDouble(const std::string &str);

	bool isLeapYear(int year);


public:
	BitcoinExchange();

	~BitcoinExchange();

	void validateInputHeader(std::ifstream *inputFile);

	void processLine(std::string &line);

	std::ifstream* getFile(const std::string &filename);

};


#endif //CPP_MODULE_BITCOINEXCHANGE_HPP
