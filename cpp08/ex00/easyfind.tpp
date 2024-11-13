#include "easyfind.hpp"

Exception easyfindException() 
{ 
    return Exception(RED "Value not found" RESET); 
}

template <typename T>
void easyfind(const T &container, const int &val)
{
    typename T::const_iterator it = find(container.begin(), container.end(), val);
    if (it != container.end())
    {
        int pos = distance(container.begin(), it);
        std::cout << GREEN "Value: " BLUE << *it << GREEN " found on position: " BLUE << pos << RESET << std::endl;
        return;
    }
    throw easyfindException();
}
