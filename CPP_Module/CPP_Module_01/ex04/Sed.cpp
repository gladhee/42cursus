#include "Sed.hpp"

Sed::Sed() {}

Sed::Sed(const std::string &filename, const std::string &str, const std::string &replace) {
	this->_filename = filename;
	this->_str = str;
	this->_replace = replace;
}

Sed::~Sed() {}

void Sed::replace() {
	std::string filename = getFilename();
	std::string str = getStr();
	std::string replace = getReplace();

	std::ifstream		ifs(filename.c_str());
	std::ofstream		ofs((filename + ".replace").c_str());
	std::string			input;

	if (!ifs.is_open() || !ofs.is_open())
		throw std::runtime_error("Error: file open failed");
	while (std::getline(ifs, input)) {
		size_t pos = 0;

		while ((pos = input.find(str, pos)) != std::string::npos) {
			input.erase(pos, str.length());
			input.insert(pos, replace);
			pos += replace.length();
		}
		if (ifs.eof())
			ofs << input;
		else
			ofs << input << std::endl;
	}
	ifs.close();
	ofs.close();
}

const std::string &Sed::getFilename() const {
	return this->_filename;
}

const std::string &Sed::getStr() const {
	return this->_str;
}

const std::string &Sed::getReplace() const {
	return this->_replace;
}

void Sed::setFilename(const std::string &filename) {
	this->_filename = filename;
}

void Sed::setStr(const std::string &str) {
	this->_str = str;
}

void Sed::setReplace(const std::string &replace) {
	this->_replace = replace;
}
