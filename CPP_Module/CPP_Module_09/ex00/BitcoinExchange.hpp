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

	void skipHeader(std::ifstream &database);

	std::map<std::string, double> processLine(std::ifstream &database);

	void validateDate(const std::string &date);

	bool isValidDate(int year, int month, int day);

	void validateQuantity(double quantity);

	double calculate(const std::string &date, double quantity);

	double stringToDouble(const std::string &str);

	bool isLeapYear(int year);


public:
	BitcoinExchange();

	~BitcoinExchange();

	void validateInputHeader(std::ifstream &inputFile);

	void processLine(std::string &line);

	std::ifstream getFile(const std::string &filename);

};


#endif //CPP_MODULE_BITCOINEXCHANGE_HPP

/*
	파일의 각 줄은 다음 형식을 따라야 합니다:
	"date | value".
	유효한 날짜 형식은 반드시 **Year-Month-Day**이어야 합니다.
	유효한 값은 0에서 1000 사이의 양의 정수 또는 부동소수점 숫자여야 합니다.

	출력 요구사항
	입력 파일의 값에 데이터베이스의 환율을 곱한 결과를 표준 출력에 표시해야 합니다.
	입력 파일에 있는 날짜가 데이터베이스에 없으면, 데이터베이스에 포함된 가장 가까운 이전 날짜를 사용해야 합니다.
	(주의: 이후 날짜가 아니라 이전 날짜를 사용해야 합니다.)

 $> ./btc
Error: could not open file.
$> ./btc input.txt
2011-01-03 => 3 = 0.9
2011-01-03 => 2 = 0.6
2011-01-03 => 1 = 0.3
2011-01-03 => 1.2 = 0.36
2011-01-09 => 1 = 0.32
Error: not a positive number.
Error: bad input => 2001-42-42
2012-01-11 => 1 = 7.1
Error: too large a number.
$>

 * */
