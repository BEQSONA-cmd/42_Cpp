#include "PmergeMe.hpp"

template <typename T>
void is_sorted(T &nums)
{
    typename T::iterator it = nums.begin();
    typename T::iterator next_it = it;
    ++next_it;
    while (next_it != nums.end())
    {
        if (*it > *next_it)
            std::cout << "Not sorted: " << *it << " > " << *next_it << std::endl;
        ++it;
        ++next_it;
    }
}

template <typename T>
T fill_nums(int ac, char **av)
{
    int i = 1;
    int arr[ac - 1];
    T nums;

    while (i < ac)
    {
        arr[i - 1] = std::atoi(av[i]);
        i++;
    }
    
    i = 1;
    while (i < ac)
    {
        nums.push_back(arr[i - 1]);
        i++;
    }

    return nums;
}

template <typename T>
void print_nums(T nums)
{
    typename T::iterator it = nums.begin();
    while (it != nums.end())
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
}

// size_t binary_serch(std::vector<int> nums, int value, size_t right_bound)
// {
//     size_t left = 0;
//     size_t right = right_bound;

//     while (left < right)
//     {
//         size_t mid = left + (right - left) / 2;

//         if (nums[mid] < value)
//             left = mid + 1;
//         else
//             right = mid;
//     }

//     return left;
// }

template <typename T>
size_t binary_search(T &nums, typename T::value_type value, size_t right_bound)
{
    typename T::iterator left = nums.begin();
    typename T::iterator right = nums.begin();

    // size_t i = 0;
    // while (i < right_bound)
    // {
    //     ++right;
    //     ++i;
    // }

    size_t pos = 0;
    std::advance(right, right_bound);

    while (left != right)
    {
        comparisons++;
        typename T::iterator mid = left;
        pos = std::distance(left, right) / 2;
        std::advance(mid, pos);

        if (*mid < value)
            left = ++mid;
        else
            right = mid;
    }
    
    pos = std::distance(nums.begin(), left);
    return pos;
}
