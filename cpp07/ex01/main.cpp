#include "Iter.hpp"

template <typename T>
void print(T const &x)
{
    std::cout << YELLOW "Printing: " BLUE << x << RESET << std::endl;
}

template <typename T>
void print_2(T &x)
{
    std::cout << YELLOW "Printing: " BLUE << x << RESET << std::endl;
}

int main()
{
    int tab[] = {0, 1, 2, 3, 4};

    const char tab2[] = {'a', 'b', 'c', 'd', 'e'};

    float tab3[] = {0.1, 0.2, 0.3, 0.4, 0.5};
    
    int size = sizeof(tab) / sizeof(tab[0]);
    int size2 = sizeof(tab2) / sizeof(tab2[0]);
    int size3 = sizeof(tab3) / sizeof(tab3[0]);

    std::cout << BLUE "Int array:" RESET << std::endl;
    
    iter<int>(tab, size, print);
    std::cout << std::endl;

    std::cout << GREEN "Char array:" RESET << std::endl;
    iter<const char>(tab2, size2, print_2);
    std::cout << std::endl;

    std::cout << CYAN "Float array:" RESET << std::endl;
    iter<float>(tab3, size3, print);
    std::cout << std::endl;

    return 0;
}
