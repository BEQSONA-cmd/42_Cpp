#include "Iter.hpp"

template <typename T>
void print(T const &x)
{
    std::cout << YELLOW "Printing: " BLUE << x << RESET << std::endl;
}

int main()
{
    int tab[] = {0, 1, 2, 3, 4};
    char tab2[] = {'a', 'b', 'c', 'd', 'e'};
    float tab3[] = {0.1, 0.2, 0.3, 0.4, 0.5};

    std::cout << BLUE "Int array:" RESET << std::endl;
    iter(tab, 5, print);
    std::cout << std::endl;

    std::cout << GREEN "Char array:" RESET << std::endl;
    iter(tab2, 5, print);
    std::cout << std::endl;

    std::cout << CYAN "Float array:" RESET << std::endl;
    iter(tab3, 5, print);
    std::cout << std::endl;

    return 0;
}