#include "PmergeMe.hpp"
size_t comparisons = 0;

template <typename T>
void Sorter<T>::group_sort_pairs(T &nums, T &a, T &b)
{
    typename T::iterator it = nums.begin();
    while (it != nums.end())
    {
        comparisons++;
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
void Sorter<T>::create_main_and_pend(T &a, T &b, T &main_chain, T &pend)
{
    typename T::iterator a_it = a.begin();
    typename T::iterator b_it = b.begin();

    if(!b.empty())
    {
        main_chain.push_back(*b_it);
        b.erase(b_it);
        b_it = b.begin();
    }

    while (a_it != a.end())
    {
        main_chain.push_back(*a_it);
        ++a_it;
    }
    while(b_it != b.end())
    {
        pend.push_back(*b_it);
        ++b_it;
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
void Sorter<T>::binary_insert(T &main_chain, T &pend)
{
    std::vector<int> order = jacob_order(pend.size());
    // jacob_order returns the specially chosen order: 3, 2, 5, 4, ...

    size_t i = 0;
    while (i < pend.size())
    {
        size_t pend_index;
        if(i < order.size())
            pend_index = order[i];
        else
            pend_index = i;
        if (pend_index >= pend.size()) continue;

        typename T::iterator it = pend.begin();
        std::advance(it, pend_index);

        size_t index = binary_search(main_chain, *it, main_chain.size());

        typename T::iterator insert_it = main_chain.begin();
        std::advance(insert_it, index);

        main_chain.insert(insert_it, *it);
        i++;
    }
}


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
