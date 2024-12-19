//
// Created by Heesung Choi on 11/19/24.
//

#include "Serializer.hpp"
#include <iostream>

int main() {
	Data data;
	data.s1 = "Hello";
	data.s2 = "World";
	data.n = 42;

	Data *data_ptr = &data;
	std::cout << "Data_ptr: " << data_ptr->s1 << data_ptr->s2 << data_ptr->n << std::endl;

	std::cout << "Data_ptr: " << data_ptr << std::endl;
	uintptr_t serialized = Serializer::serialize(data_ptr);

	std::cout << "Serialized: " << serialized << std::endl;
	Data *deserialized = Serializer::deserialize(serialized);
	std::cout << "Deserialized: " << deserialized << std::endl;

	std::cout << "Deserialized: " << deserialized->s1 << deserialized->s2 << deserialized->n << std::endl;

	return 0;
}
