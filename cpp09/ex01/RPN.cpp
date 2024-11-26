#include "RPN.hpp"

void RPN::calculate(std::string arguments)
{
    if(arguments.empty() || arguments.size() < 5)
        throw Exception(RED "Invalid arguments" RESET);
    std::string::iterator it = arguments.begin();
    std::stack<double> numbers;

    while (it != arguments.end())
    {
        if (DIGIT(*it))
        {
            double number = 0;
            number = number * 10 + *it - '0';
            numbers.push(number);
        }
        else if (OPERATOR(*it))
        {
            if (numbers.size() < 2)
                throw Exception(RED "Invalid arguments" RESET);
            double last = numbers.top(); numbers.pop();
            double before_last = numbers.top(); numbers.pop();
            switch (*it)
            {
                case '+': numbers.push(before_last + last); break;
                case '-': numbers.push(before_last - last); break;
                case '*': numbers.push(before_last * last); break;
                case '/': numbers.push(before_last / last); break;
            }
        }
        if (*(++it) != ' ' && *it != '\0')
            throw Exception(RED "Invalid character" RESET);
        while (*it == ' ')
            it++;
    }
    if (numbers.size() != 1)
        throw Exception(RED "Invalid arguments" RESET);
    std::cout << numbers.top() << std::endl;
}
