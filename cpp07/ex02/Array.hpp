#ifndef ARRAY_HPP
#define ARRAY_HPP
#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define BLUE "\033[1;34m"
#define CYAN "\033[1;36m"
#define RESET "\033[0m"
#include <iostream>
#include <exception>
#include <string>

class Exception : public std::exception
{
    private:
        std::string message;
    public:
        Exception(std::string message){ this->message = message; }
        virtual ~Exception() throw() {}
        virtual const char *what() const throw(){ return this->message.c_str(); }
};

template <typename T>
class Array
{
    private:
        T *array;
        unsigned int _size;
    public:
        Array();

        Array(const Array &array);
        Array &operator=(const Array &array);
        ~Array();

        Array(unsigned int n);
        T &operator[](unsigned int iter);
        unsigned int size() { return this->_size; }

        Exception outOfBoundsException() { return Exception( RED "Out of bounds" RESET ); }
};

template <typename T>
std::ostream &operator<<(std::ostream &out, const Array<T> &array);

#include "Array.tpp"

#endif
