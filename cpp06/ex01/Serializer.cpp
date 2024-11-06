#include "Serializer.hpp"

Serializer::Serializer()
{
    std::cout << YELLOW << "Serializer default constructor" << RESET << std::endl;
}

Serializer::Serializer(const Serializer &serializer)
{
    std::cout << YELLOW << "Serializer copy constructor" << RESET << std::endl;
    *this = serializer;
}

Serializer &Serializer::operator=(const Serializer &serializer)
{
    std::cout << YELLOW << "Serializer assignation operator" << RESET << std::endl;
    if (this == &serializer)
        return *this;
    return *this;
}

Serializer::~Serializer()
{
    std::cout << YELLOW << "Serializer destructor" << RESET << std::endl;
}

uintptr_t Serializer::serialize(Data* ptr)
{
    uintptr_t pointer = reinterpret_cast<uintptr_t>(ptr);

    std::stringstream pointer_in_hex;
    pointer_in_hex << std::hex << pointer;

    std::cout << GREEN << "returning pointer: " BLUE << "0x" << pointer_in_hex.str() << RESET << std::endl;
    return pointer;
}

Data* Serializer::deserialize(uintptr_t raw)
{
    Data *data;
    data = reinterpret_cast<Data *>(raw);

    std::cout << GREEN "returning data->str: " BLUE << data->str << RESET << std::endl;
    std::cout << GREEN "returning data->num: " BLUE << data->num << RESET << std::endl;
    return data;
}