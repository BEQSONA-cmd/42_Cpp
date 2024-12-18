#ifndef ITER_HPP
#define ITER_HPP
#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define BLUE "\033[1;34m"
#define CYAN "\033[1;36m"
#define RESET "\033[0m"
#include <iostream>

template <typename T>
void iter(const T *array, int length, void (*f)(T const &))
{
    int i = 0;
    if(!array || !f || length <= 0)
    {
        std::cout << RED "Error: Invalid input" RESET << std::endl;
        return;
    }
    while (i < length)
    {
        f(array[i]);
        i++;
    }
}

#endif