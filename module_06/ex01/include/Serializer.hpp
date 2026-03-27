#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdint.h>
# include "Data.hpp"

class Serializer {

private:
	Serializer(void);
	Serializer(const Serializer& copy);
	Serializer& operator=(const Serializer& copy);
	~Serializer(void);

public:
	static uintptr_t	deserialize(Data* ptr);
	static Data*		serialize(uintptr_t raw);

};

#endif