#ifndef ARRAY_HPP
#define ARRAY_HPP
#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define BLUE "\033[1;34m"
#define CYAN "\033[1;36m"
#define RESET "\033[0m"
#include <iostream>

template <typename T>
class Array
{
    private:
        T *_array;
        unsigned int _size;
    public:
        Array();
        Array(const Array &array);
        Array &operator=(const Array &array);
        ~Array();
};

#endif
