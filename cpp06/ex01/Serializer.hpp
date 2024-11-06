#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define BLUE "\033[1;34m"
#define CYAN "\033[1;36m"
#define RESET "\033[0m"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <stdint.h>

struct Data
{
    std::string str;
    int num;
};

class Serializer
{
    private:
    public:
        Serializer();
        Serializer(const Serializer &serializer);
        Serializer &operator=(const Serializer &serializer);
        ~Serializer();

        uintptr_t serialize(Data* ptr);
        Data* deserialize(uintptr_t raw);
};

#endif
