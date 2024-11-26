#ifndef RPN_HPP
#define RPN_HPP
#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define BLUE "\033[1;34m"
#define CYAN "\033[1;36m"
#define RESET "\033[0m"
#include <iostream>
#include <stack>
#include <algorithm>
#include <exception>

#define OPERATOR(x) (x == '+' || x == '-' || x == '*' || x == '/')
#define DIGIT(x) (x >= '0' && x <= '9')
class Exception : public std::exception
{
    private:
        std::string message;
    public:
        Exception(std::string message){ this->message = message; }
        virtual ~Exception() throw() {}
        virtual const char *what() const throw(){ return this->message.c_str(); }
};

class RPN
{
    private:
        RPN() {};
        RPN(const RPN &rpn) { (void)rpn; };
        RPN &operator=(const RPN &rpn) { (void)rpn; return *this; };
        ~RPN() {};

    public:
        static void calculate(std::string arguments);
};

#endif
