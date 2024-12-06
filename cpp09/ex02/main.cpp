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

    std::vector<int> vector = fill_nums<std::vector<int> >(ac, av);
    std::list<int> list = fill_nums<std::list<int> >(ac, av);
    std::deque<int> deque = fill_nums<std::deque<int> >(ac, av);

    Sorter<std::vector<int> >::PmergeMe(vector);
    // Sorter<std::list<int> >::PmergeMe(list);
    // Sorter<std::deque<int> >::PmergeMe(deque);

    std::cout << "Sorted: " << std::endl;
    print_nums(vector);
    std::cout << std::endl;
    // print_nums(list);
    // std::cout << std::endl;
    // print_nums(deque);
    // std::cout << std::endl;

    std::cout << "Comparisons: " << comparisons << std::endl;


    return 0;
}