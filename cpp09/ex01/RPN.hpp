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

#define OPERATOR(x) (x == '+' || x == '-' || x == '*' || x == '/')
#define DIGIT(x) (x >= '0' && x <= '9')

enum eToken
{
    ADD,
    SUB,
    MUL,
    DIV
};

class RPN
{
    private:
        std::stack<double> numbers;
        std::stack<eToken> operators;

        RPN() {};
        RPN(const RPN &rpn) { (void)rpn; };
        RPN &operator=(const RPN &rpn) { (void)rpn; return *this; };

    public:
        RPN(std::string arguments);
        ~RPN() {};

        void operation(eToken token);
        void calculate(void);
};

#endif
