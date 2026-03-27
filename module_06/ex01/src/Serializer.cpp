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

    uintptr_t   serialize(Data* ptr) {
        return (reinterpreter_cast<uintptr_t>(ptr));
    }

    Data*       deserialize(uintptr_t raw) {
        return (reinterpreter_cast<Data*>(raw));
    }
