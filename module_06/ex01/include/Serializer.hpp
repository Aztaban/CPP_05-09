#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <cstdint>
# include "Data.hpp"

class Serializer {

private:
    Serializer(void);
    Serializer(const Serializer& copy);
    Serializer& operator=(const Serializer& copy);
    ~Serializer(void);

public:
    uintptr_t   serialize(Data* ptr);
    Data*       deserialize(uintptr_t raw);

};

#endif