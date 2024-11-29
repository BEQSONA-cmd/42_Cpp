#include "PmergeMe.hpp"

void print(std::vector<int> nums)
{
    size_t i = 0;
    while(i < nums.size())
    {
        std::cout << nums[i] << " ";
        i++;
    }
    std::cout << std::endl;
}

void print_pairs(std::vector<int> a)
{
    size_t i = 0;
    if(a.size() == 0)
        return;
    if(a.size() == 1)
    {
        std::cout << "[ " << a[0] << " ]";
        return;
    }

    if(a.size() % 2 != 0)
    {
        std::cout << "[ " << a[0] << " ]";
        i++;
    }
    while(i < a.size())
    {
        std::cout << "[ " << a[i] << ", " << a[i + 1] << " ]";
        i += 2;
    }
}