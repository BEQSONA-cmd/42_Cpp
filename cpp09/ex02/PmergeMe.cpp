#include "PmergeMe.hpp"

void init(std::vector<int> &num_vector, char **av)
{
    int i = 1;
    while (av[i])
    {
        num_vector.push_back(atoi(av[i]));
        i++;
    }
}

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
