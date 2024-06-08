#include <iostream>
#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define BLUE "\033[1;34m"
#define RESET "\033[0m"

int main(void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << YELLOW << "explenation of the code:" << RESET << std::endl;
    std::cout << RED << "STRING: [HI THIS IS BRAIN]" << RESET << std::endl;
    std::cout << GREEN << "GET STRING FROM STRPTR: [*stringPTR = &str]" << RESET << std::endl;
    std::cout << BLUE << "GET STRING FROM STRREF: [&stringREF = str]" << RESET << std::endl << std::endl;

    std::cout << YELLOW << "printing addresses: " << RESET << std::endl;
    std::cout << RED << "Address in memory of the string: " << &str << RESET << std::endl;
    std::cout << GREEN << "Address in memory of the stringPTR: " << stringPTR << RESET << std::endl;
    std::cout << BLUE << "Address in memory of the stringREF: " << &stringREF << RESET << std::endl;

    std::cout << std::endl;
    std::cout << YELLOW << "printing values: " << RESET << std::endl;
    std::cout << RED << "String: " << str << RESET << std::endl;
    std::cout << GREEN << "StringPTR: " << *stringPTR << RESET << std::endl;
    std::cout << BLUE << "StringREF: " << stringREF << RESET << std::endl;
    return (0);
}
