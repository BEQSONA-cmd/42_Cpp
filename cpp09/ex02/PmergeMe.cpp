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

int jacobsthal(int n)
{
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}
