#include "PmergeMe.hpp"

void merge_and_insert(std::vector<std::pair<int, int> > &left, std::vector<std::pair<int, int> > &right, std::vector<std::pair<int, int> > &nums)
{
    std::vector<std::pair<int, int> > result;
    size_t i = 0;
    size_t j = 0;

    while(i < left.size() && j < right.size())
    {
        if(left[i].first <= right[j].first)
        {
            result.push_back(left[i]);
            i++;
        }
        else
        {
            result.push_back(right[j]);
            j++;
        }
    }
    while(i < left.size())
    {
        result.push_back(left[i]);
        i++;
    }
    while(j < right.size())
    {
        result.push_back(right[j]);
        j++;
    }
    nums = result;
}

void recursive_sort_larger_element(std::vector<std::pair<int, int> > &nums)
{
    if(nums.size() <= 1)
        return;
    size_t i = 0;

    std::vector<std::pair<int, int> > left;
    std::vector<std::pair<int, int> > right;
    size_t mid = nums.size() / 2;

    while(i < mid)
    {
        left.push_back(nums[i]);
        i++;
    }
    while(i < nums.size())
    {
        right.push_back(nums[i]);
        i++;
    }
    recursive_sort_larger_element(left);
    recursive_sort_larger_element(right);

    merge_and_insert(left, right, nums);
}

void PmergeMe(std::vector<int> &nums)
{
    if(nums.size() <= 1)
        return;

    bool has_stragler = false;
    int stragler = 0;
    if(nums.size() % 2 != 0)
    {
        has_stragler = true;
        stragler = nums[nums.size() - 1];
        nums.pop_back();
    }
    (void)has_stragler;
    (void)stragler;

    std::cout << "First: Creating pairs" << std::endl;
    std::vector<std::pair<int, int> > pairs = create_pairs(nums);

    std::cout << "Second: Swapping pairs" << std::endl;
    swap_pairs(pairs);
    
    std::cout << "Third: Sorting pairs recursively" << std::endl;
    recursive_sort_larger_element(pairs);
}

int main(int ac, char **av)
{
    // std::cout << jacobsthal(9) << std::endl;
    if(ac < 2)
    {
        std::cerr << "Usage: ./PmergeMe [num1] [num2] [num3] ..." << std::endl;
        return 1;
    }
    std::vector<int> num_vector;
    init(num_vector, av);

    PmergeMe(num_vector);

    // print(num_vector);


    return 0;
}
