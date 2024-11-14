#include "Span.hpp"
#include <ctime>

// int main()
// {
//     Span sp = Span(5);
//     sp.addNumber(6);
//     sp.addNumber(3);
//     sp.addNumber(17);
//     sp.addNumber(9);
//     sp.addNumber(11);
//     std::cout << sp.shortestSpan() << std::endl;
//     std::cout << sp.longestSpan() << std::endl;
//     return(0);
// }

void full_array(void)
{
    Span sp = Span(5);
    try
    {
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        sp.addNumber(11);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}

void span_test(void)
{
    int size = 10000000;
    Span sp = Span(size);
    try
    {
        int i = 0;
        while (i < size)
        {
            sp.addNumber(rand());
            i++;
        }
        std::cout << GREEN "Shortest span: " BLUE << sp.shortestSpan() << RESET << std::endl;
        std::cout << GREEN "Longest span: " BLUE << sp.longestSpan() << RESET << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}

void basic_test(void)
{
    Span sp = Span(5);
    try
    {
        sp.addNumber(1);
        sp.addNumber(1);
        sp.addNumber(-100);
        sp.addNumber(100);
        std::cout << GREEN "Shortest span: " BLUE << sp.shortestSpan() << RESET << std::endl;
        std::cout << GREEN "Longest span: " BLUE << sp.longestSpan() << RESET << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}

void improved_add_number(void)
{
    Span sp = Span(10);
    try
    {
        sp.addNumber(1, 5);
        std::cout << GREEN "Shortest span: " BLUE << sp.shortestSpan() << RESET << std::endl;
        std::cout << GREEN "Longest span: " BLUE << sp.longestSpan() << RESET << std::endl;
        sp.addNumber(100, 5);
        std::cout << GREEN "Shortest span: " BLUE << sp.shortestSpan() << RESET << std::endl;
        std::cout << GREEN "Longest span: " BLUE << sp.longestSpan() << RESET << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}


int main() 
{
    srand(time(NULL));
    
    std::cout << YELLOW "Full array test" RESET << std::endl;
    full_array();

    std::cout << YELLOW "Shortest and longest span test" RESET << std::endl;
    span_test();

    std::cout << YELLOW "Basic test" RESET << std::endl;
    basic_test();

    std::cout << YELLOW "Improved add number test" RESET << std::endl;
    improved_add_number();

    return 0;
}