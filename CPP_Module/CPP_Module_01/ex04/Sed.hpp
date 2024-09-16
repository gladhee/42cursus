#pragma once
#ifndef SED_HPP
#define SED_HPP

#include <iostream>
#include <fstream>
#include <string>

class Sed {
private:
	std::string		_filename;
	std::string		_str;
	std::string		_replace;

public:
	Sed();
	~Sed();

	void replace();

	const std::string &getFilename() const;
	const std::string &getStr() const;
	const std::string &getReplace() const;

	void setFilename(const std::string &filename);
	void setStr(const std::string &str);
	void setReplace(const std::string &replace);

};

#endif