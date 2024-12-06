#include "PmergeMe.hpp"

bool is_jacobsthal(size_t num)
{
    size_t i = 3;
    while (true) 
    {
        size_t jacob_value = jacobsthal(i);
        if (jacob_value == num) return true;
        if (jacob_value > num) return false;
        i++;
    }
}

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

    T order = jacob_order<T>(pend.size());
    // jacob order is : 3 2 5 4 11 10 9 8 7 6 21 20 19 ...

    T sorted_pend(pend.size());
    typename T::iterator pend_it = pend.begin();
    typename T::iterator order_it = order.begin();
    while (pend_it != pend.end())
    {
        if(order_it != order.end())
        {
            sorted_pend[*order_it] = *pend_it;
            ++order_it;
        }
        else
            sorted_pend[std::distance(pend.begin(), pend_it)] = *pend_it;
        ++pend_it;
    }
    pend = sorted_pend;

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
void Sorter<T>::sort_b_on_order(T &a, T &b, std::map<int, value> &a_order)
{
    std::vector<value> b_sorted(b.size());

    typename T::const_iterator a_it = a.begin();
    typename T::const_iterator b_it = b.begin();
    typename std::vector<value>::iterator it = b_sorted.begin();

    // if(b.size() > a_order.size())
    // {
    //     std::cout << "b size is more" << std::endl;
    //     std::cout << "b size: " << b.size() << std::endl;
    //     std::cout << "a_order size: " << a_order.size() << std::endl;
    // }
    // else if(b.size() < a_order.size())
    //     std::cout << "a size is more" << std::endl;
    // else
    //     std::cout << "equal" << std::endl;

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
