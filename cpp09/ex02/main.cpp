#include "PmergeMe.hpp"

void PmergeMe(std::vector<int> nums)
{
    size_t i = 0;
    while(i < nums.size())
    {
        i++;
    }
}


int main(int ac, char **av)
{
    if(ac < 2)
    {
        std::cerr << "Usage: ./PmergeMe [num1] [num2] [num3] ..." << std::endl;
        return 1;
    }
    std::vector<int> num_vector;
    init(num_vector, av);

    PmergeMe(num_vector);

    print(num_vector);

    return 0;
}
