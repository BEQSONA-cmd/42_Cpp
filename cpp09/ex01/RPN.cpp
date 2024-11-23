#include "RPN.hpp"

RPN::RPN(std::string arguments)
{
    std::string::iterator it = arguments.begin();
    while (it != arguments.end())
    {
        if (DIGIT(*it))
        {
            double number = 0;
            while (DIGIT(*it))
            {
                number = number * 10 + *it - '0';
                it++;
            }
            numbers.push(number);
        }
        else if (OPERATOR(*it))
        {
            switch (*it)
            {
                case '+': operators.push(ADD); break;
                case '-': operators.push(SUB); break;
                case '*': operators.push(MUL); break;
                case '/': operators.push(DIV); break;
            }
            it++;
        }
        else
            it++;
    }
}

void RPN::operation(eToken token)
{
    double a = numbers.top();
    numbers.pop();
    double b = numbers.top();
    numbers.pop();
    switch (token)
    {
        case ADD: numbers.push(a + b); break;
        case SUB: numbers.push(a - b); break;
        case MUL: numbers.push(a * b); break;
        case DIV: numbers.push(a / b); break;
    }
}

void RPN::calculate(void)
{
    while (!operators.empty())
    {
        operation(operators.top());
        operators.pop();
    }
    std::cout << numbers.top() << std::endl;
}
