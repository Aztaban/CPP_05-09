#include "Serializer.hpp"

int main(void) {
    Data data;

    data.id = 1;
    data.name = "Bobo";

    Data* originalPtr = &data;
    uintptr_t rawPtr = Serializer::deserialize(originalPtr);
    Data* newPtr = Serializer::serialize(rawPtr);

    std::cout << YELLOW << "\n-- Pointers print --" << RESET << std::endl;
    std::cout << "original pointer: " << BLUE << originalPtr << RESET << std::endl;
    std::cout << "deserialized pointer: " << BLUE << newPtr << RESET << std::endl;

    std::cout << YELLOW << "\n-- Equality check --" << RESET << std::endl;
    if (originalPtr == newPtr)
        std::cout << GREEN << "\nPointers are equal." << RESET << std::endl;
    else
        std::cout << RED << "\nPointers are not equal." << RESET << std::endl;

    std::cout << YELLOW << "\n-- Original pointer data --" << RESET << std::endl;
    std::cout << "id: " << BLUE << originalPtr->id << RESET << std::endl;
    std::cout << "name: " << BLUE << originalPtr->name << RESET << std::endl;

    std::cout << YELLOW << "\n -- Deserialized pointer data --" << RESET << std::endl;
    std::cout << "id: " << BLUE << originalPtr->id << RESET << std::endl;
    std::cout << "name: " << BLUE << originalPtr->name << RESET << std::endl;
}