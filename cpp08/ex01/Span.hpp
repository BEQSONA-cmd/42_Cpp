#ifndef SPAN_HPP
#define SPAN_HPP
#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define BLUE "\033[1;34m"
#define CYAN "\033[1;36m"
#define RESET "\033[0m"
#include <iostream>
#include <algorithm>
#include <vector>
#include <exception>

class Exception : public std::exception
{
    private:
        std::string message;
    public:
        Exception(std::string message){ this->message = message; }
        virtual ~Exception() throw() {}
        virtual const char *what() const throw(){ return this->message.c_str(); }
};


class Span
{
    private:
        unsigned int len;
        std::vector<int> arr;

    public:
        Span();
        Span(unsigned int N);
        Span(Span const &other);
        Span &operator=(Span const &other);
        ~Span();

        void addNumber(int n);
        int shortestSpan(void);
        int longestSpan(void);

        std::vector<int> getArr(void);

        Exception ArrayIsFull() { return Exception(RED "Array is full" RESET); }
        Exception NotEnoughElements() { return Exception(RED "Not enough elements" RESET); }

};

#endif
