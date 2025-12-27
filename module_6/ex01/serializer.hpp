#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

typedef struct Data
{
    int number;
} data;

class Serializer
{
    private:
            Serializer();
            Serializer(const Serializer &other);
            Serializer& operator=(const Serializer &other);
            ~Serializer();

    public:
            static uintptr_t serialize(data* ptr);
            static data* deserialize(uintptr_t raw);
};

#endif
