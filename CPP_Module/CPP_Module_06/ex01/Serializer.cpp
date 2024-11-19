//
// Created by Heesung Choi on 11/19/24.
//

#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer &serializer) {
	(void) serializer;
}

Serializer &Serializer::operator=(const Serializer &serializer) {
	(void) serializer;
	return *this;
}

Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data *ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);
}
