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

int jacobsthal(int n)
{
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

void print_pairs(std::vector<std::pair<int, int > > &pairs)
{
    for (size_t i = 0; i < pairs.size(); i++)
        std::cout << "[" << pairs[i].first << ", " << pairs[i].second << "]" << std::endl;
}

void swap_pairs(std::vector<std::pair<int, int> > &pairs)
{
    size_t i = 0;
    while (i < pairs.size())
    {
        if (pairs[i].second > pairs[i].first)
            std::swap(pairs[i].second, pairs[i].first);
        i++;
    }
}

std::vector<std::pair<int, int> > create_pairs(std::vector<int> &nums)
{
    std::vector<std::pair<int, int> > pairs;

    size_t i = 0;
    while (i < nums.size())
    {
        if (i + 1 < nums.size())
            pairs.push_back(std::make_pair(nums[i], nums[i + 1]));
        i += 2;
    }
    return pairs;
}