//
// Created by Heesung Choi on 11/19/24.
//

#ifndef CPP_MODULE_SERIALIZER_HPP
#define CPP_MODULE_SERIALIZER_HPP

#include <string>

struct Data {
	std::string s1;
	std::string s2;
	int n;
};

class Serializer {

private:
	Serializer();

	Serializer(const Serializer &serializer);

	Serializer &operator=(const Serializer &serializer);

public:
	~Serializer();

	static uintptr_t serialize(Data *ptr);

	static Data *deserialize(uintptr_t raw);

};


#endif //CPP_MODULE_SERIALIZER_HPP
