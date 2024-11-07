#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP
#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define BLUE "\033[1;34m"
#define CYAN "\033[1;36m"
#define RESET "\033[0m"

#include <iostream>

template <typename T>
void swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
T min(T &a, T &b)
{
    if(a < b)
        return a;
    return b;
}
template <typename T>
T max(T &a, T &b)
{
    if(a > b)
        return a;
    return b;
}


#endif