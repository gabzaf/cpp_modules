#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

struct Data
{
    int number;
};

class Serializer
{
    private:
            Serializer();
            Serializer(const Serializer &original);
            Serializer& operator=(const Serializer &original);
            ~Serializer();

    public:
            static uintptr_t serialize(Data* ptr);
            static Data* deserialize(uintptr_t raw);
};

#endif