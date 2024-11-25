#include "RPN.hpp"

void RPN::calculate(std::string arguments)
{
    std::string::iterator it = arguments.begin();
    std::stack<double> numbers;

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
            double last = numbers.top();
            numbers.pop();
            double before_last = numbers.top();
            numbers.pop();

            switch (*it)
            {
                case '+': numbers.push(before_last + last); break;
                case '-': numbers.push(before_last - last); break;
                case '*': numbers.push(before_last * last); break;
                case '/': numbers.push(before_last / last); break;
            }
        }
        it++;

    }
    std::cout << GREEN "Result: " BLUE << numbers.top() << RESET "\n";
}
