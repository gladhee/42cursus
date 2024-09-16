#include "Sed.hpp"

Sed::Sed() {}

Sed::~Sed() {}

void Sed::replace() {
	std::string filename = getFilename();
	std::string str = getStr();
	std::string replace = getReplace();

	std::ifstream		ifs(filename);
	std::ofstream		ofs(filename + ".replace");
	std::string			input;

	if (!ifs.is_open() || !ofs.is_open())
		throw std::runtime_error("Error: file open failed");
	while (std::getline(ifs, input)) {
		size_t pos = 0;

		while ((pos = line.find(str, pos)) != std::string::npos) {
			input.replace(pos, str.length(), replace);
			pos += replace.length();
		}
		ofs << line << std::endl;
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
