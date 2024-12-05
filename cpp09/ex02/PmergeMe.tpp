#include "PmergeMe.hpp"

template <typename T>
std::map<int, typename T::value_type> Sorter<T>::get_map(T &a)
{
    std::map<int, value> a_order;
    value i = 0;
    typename T::iterator a_it = a.begin();

    while (a_it != a.end())
    {
        a_order[*a_it] = i;
        ++a_it;
        ++i;
    }

    return a_order;
}

template <typename T>
size_t Sorter<T>::binary_search(T &nums, value value, size_t right_bound)
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
void Sorter<T>::binary_insert(T &main_chain, T &pend)
{
    typename T::iterator it = pend.begin();

    // if(is_jacobsthal(pend.size()))
    // {
    //     T order = jacob_order<T>(pend.size());
    //     typename T::iterator order_it = order.begin();

    //     while (order_it != order.end())
    //     {
    //         size_t index = binary_search(main_chain, *it, main_chain.size());
    //         typename T::iterator insert_it = main_chain.begin();
    //         std::advance(insert_it, index);
    //         main_chain.insert(insert_it, *it);
    //         ++it;
    //         ++order_it;
    //     }
    // }
    // else
    {
        while (it != pend.end())
        {
            size_t index = binary_search(main_chain, *it, main_chain.size());
            typename T::iterator insert_it = main_chain.begin();
            std::advance(insert_it, index);
            main_chain.insert(insert_it, *it);
            ++it;
        }
    }
}

// template <typename T>
// std::map<int, int> get_map(T &a)
// {
//     std::map<int, int> a_order;
//     int i = 0;
//     typename T::iterator a_it = a.begin();

//     while (a_it != a.end())
//     {
//         a_order[*a_it] = i;
//         ++a_it;
//         ++i;
//     }

//     return a_order;
// }

// template <typename T>
// void sort_b_on_order(T &a, T &b, std::map<int, int> &a_order)
// {

//     std::vector<int> b_sorted(b.size());
//     size_t i = 0;
//     while (i < b.size())
//     {
//         b_sorted[a_order[a[i]]] = b[i];
//         i++;
//     }
//     b = b_sorted;
// }


template <typename T>
void Sorter<T>::sort_b_on_order(T &a, T &b, std::map<int, value> &a_order)
{
    std::vector<value> b_sorted(b.size());

    typename T::const_iterator a_it = a.begin();
    typename T::const_iterator b_it = b.begin();
    typename std::vector<value>::iterator it = b_sorted.begin();

    while (a_it != a.end() && b_it != b.end())
    {
        b_sorted[a_order[*a_it]] = *b_it;
        ++a_it, ++b_it;
    }
    
    typename T::iterator b_target = b.begin();
    while (b_target != b.end() && it != b_sorted.end())
    {
        *b_target = *it;
        ++b_target, ++it;
    }
}

template <typename T>
void Sorter<T>::PmergeMe(T &nums)
{
    if (nums.size() <= 1)
        return;

    bool has_stragler = false;
    value stragler;

    if (nums.size() % 2 != 0)
    {
        has_stragler = true;
        typename T::iterator it = nums.end();
        --it;
        stragler = *it;
        nums.pop_back();
    }

    T a = T(); T b = T();
    group_sort_pairs(nums, a, b);
    std::map<int, value> a_order = get_map(a);
    
    PmergeMe(a);

    sort_b_on_order(a, b, a_order);

    T main_chain = T(); T pend = T();
    create_main_and_pend(a, b, main_chain, pend);

    if(has_stragler)
        pend.push_back(stragler);

    binary_insert(main_chain, pend);
    nums = main_chain;
}
