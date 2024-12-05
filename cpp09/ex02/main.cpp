#include "PmergeMe.hpp"

void print_diff(std::vector<int> nums, std::vector<int> nums_2)
{
    size_t i = 0;
    while(i < nums.size())
    {
        int check_num = nums[i];
        size_t j = 0;
        bool is_num = false;
        while(j < nums_2.size())
        {
            if(nums[i] == nums_2[j])
            {
                is_num = true;
                break;
            }
            j++;
        }
        i++;
        if(!is_num)
            std::cout << check_num << std::endl;
    }
}

int main(int ac, char **av)
{

    std::vector<int> nums = fill_nums<std::vector<int> >(ac, av);
    std::vector<int> nums_2 = fill_nums<std::vector<int> >(ac, av);

    Sorter<std::vector<int> >::PmergeMe(nums);

    std::cout << "Sorted: " << std::endl;
    print_nums(nums);
    std::cout << std::endl;

    std::cout << "numbers missing: " << std::endl;
    print_diff(nums_2, nums);

    return 0;
}
