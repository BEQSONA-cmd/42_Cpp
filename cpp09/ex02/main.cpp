#include "PmergeMe.hpp"

template <typename T>
void group_sort_pairs(T &nums, T &a, T &b)
{
    typename T::iterator it = nums.begin();
    while (it != nums.end())
    {
        typename T::iterator next_it = it;
        ++next_it;
        if (next_it == nums.end()) // Handle odd-sized list
            break;

        if (*it < *next_it)
        {
            a.push_back(*next_it);
            b.push_back(*it);
        }
        else
        {
            a.push_back(*it);
            b.push_back(*next_it);
        }

        ++it;
        ++it; // Move iterator forward by 2
    }
}

template <typename T>
size_t binary_search(T &nums, int value, size_t right_bound)
{
    typename T::iterator left = nums.begin();
    typename T::iterator right = nums.begin();

    for (size_t i = 0; i < right_bound; ++i)
        ++right;

    while (left != right)
    {
        typename T::iterator mid = left;
        for (size_t i = 0; i < (size_t)std::distance(left, right) / 2; ++i)
            ++mid;

        if (*mid < value)
            left = ++mid;
        else
            right = mid;
    }

    return std::distance(nums.begin(), left);
}


template <typename T>
void binary_insert(T &main_chain, T &pend)
{
    for (typename T::iterator it = pend.begin(); it != pend.end(); ++it)
    {
        size_t index = binary_search(main_chain, *it, main_chain.size());
        typename T::iterator insert_it = main_chain.begin();
        for (size_t i = 0; i < index; ++i)
            ++insert_it;
        main_chain.insert(insert_it, *it);
    }
}


template <typename T>
void PmergeMe(T &nums)
{
    if (nums.size() <= 1)
        return;

    bool has_stragler = false;
    int stragler = 0;

    if (nums.size() % 2 != 0)
    {
        has_stragler = true;
        typename T::iterator it = nums.end();
        --it; // Move to the last element
        stragler = *it; // Store the last element
        nums.pop_back(); // Remove the last element
    }

    T a, b;
    group_sort_pairs(nums, a, b);
    PmergeMe(a);

    if (has_stragler)
        b.push_back(stragler);

    binary_insert(a, b);
    nums = a;
}

int main(int ac, char **av)
{
    int i = 1;
    int arr[ac - 1];

    while (i < ac)
    {
        arr[i - 1] = std::atoi(av[i]);
        i++;
    }

    std::vector<int> nums;
    std::list<int> list;

    for (int i = 1; i < ac; i++)
        nums.push_back(arr[i - 1]);
        
    for (int i = 1; i < ac; i++)
        list.push_back(arr[i - 1]);

    PmergeMe(nums);
    PmergeMe(list);
    std::cout << "Sorted array: " << std::endl;
    print_nums(nums);
    print_nums(list);
    std::cout << std::endl;

    return 0;
}
