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

	static const std::string DATA_FILE;
	static const std::string DATE;
	static const std::string EXCHANGE_RATE;
	static const std::string INPUT_DELIMITER;
	static const std::string VALUE;

private:
	std::map<std::string, double> exchangeRate;


	void validateDatabaseHeader(const std::string &line) const;

	void processLine(std::map<std::string, double> &exchangeRate, const std::string &line);


public:
	std::map<std::string, double> loadExchangeRate(const std::string &filename);

	BitcoinExchange();

	BitcoinExchange(const BitcoinExchange &other);

	BitcoinExchange &operator=(const BitcoinExchange &other);

	~BitcoinExchange();



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
 * */
