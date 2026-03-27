#include "Serializer.hpp"

Serializer::Serializer(void) {}

Serializer::Serializer(const Serializer& copy) {
	(void)copy;
}

Serializer& Serializer::operator=(const Serializer& copy) {
	(void)copy;
	return *this;
}

Serializer::~Serializer(void) {}

Data*	Serializer::serialize(uintptr_t ptr) {
	return (reinterpret_cast<Data*>(ptr));
}

uintptr_t	Serializer::deserialize(Data* raw) {
	return (reinterpret_cast<uintptr_t>(raw));
}
