#include "PmergeMe.hpp"

template <typename T>
void group_sort_pairs(T &nums, T &a, T &b)
{
    typename T::iterator it = nums.begin();
    while (it != nums.end())
    {
        typename T::iterator next_it = it;
        ++next_it;
        if (next_it == nums.end())
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
        ++it; ++it;
    }
}

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
    std::advance(right, right_bound);

    while (left != right)
    {
        typename T::iterator mid = left;
        std::advance(mid, std::distance(left, right) / 2);

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
    typename T::iterator it = pend.begin();

    while (it != pend.end())
    {
        size_t index = binary_search(main_chain, *it, main_chain.size());

        typename T::iterator insert_it = main_chain.begin();
        
        std::advance(insert_it, index);
        main_chain.insert(insert_it, *it);
        ++it;
    }
}

template <typename T>
void PmergeMe(T &nums)
{
    if (nums.size() <= 1)
        return;

    bool has_stragler = false;
    typename T::value_type stragler;

    if (nums.size() % 2 != 0)
    {
        has_stragler = true;
        typename T::iterator it = nums.end();
        --it;
        stragler = *it;
        nums.pop_back();
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
    std::deque<int> deque;

    for (int i = 1; i < ac; i++)
        nums.push_back(arr[i - 1]);
        
    for (int i = 1; i < ac; i++)
        list.push_back(arr[i - 1]);
    
    for (int i = 1; i < ac; i++)
        deque.push_back(arr[i - 1]);

    PmergeMe(nums);
    PmergeMe(list);
    PmergeMe(deque);
    std::cout << "Sorted array: " << std::endl;
    print_nums(nums);
    print_nums(list);
    print_nums(deque);
    std::cout << std::endl;

    return 0;
}
