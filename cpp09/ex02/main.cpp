#include "PmergeMe.hpp"

void merge_and_insert(std::vector<int> left, std::vector <int> right, std::vector<int> &nums)
{
    std::vector<int> result;
    size_t i = 0;
    size_t j = 0;

    while(i < left.size() && j < right.size())
    {
        if(left[i] <= right[j])
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

void PmergeMe(std::vector<int> &nums)
{
    if(nums.size() <= 1)
        return;
    size_t i = 0;

    std::vector<int> left;
    std::vector<int> right;
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
    PmergeMe(left);
    PmergeMe(right);

    merge_and_insert(left, right, nums);
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
