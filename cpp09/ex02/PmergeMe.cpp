#include "PmergeMe.hpp"
size_t comparisons = 0;

size_t jacobsthal(size_t num)
{
    size_t jacob[] = 
    {
        0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461,
        10923, 21845, 43691, 87381, 174763, 349525, 699051, 1398101, 2796203,
        5592405, 11184811, 22369621, 44739243, 89478485, 178956971, 357913941,
        715827883, 1431655765, 2863311531, 5726623061, 11453246123, 22906492245,
        45812984491, 91625968981, 183251937963, 366503875925, 733007751851,
        1466015503701, 2932031007403, 5864062014805, 11728124029611, 23456248059221,
        46912496118443, 93824992236885, 187649984473771, 375299968947541, 750599937895081,
        1501199875790163, 3002399751580325, 6004799503160651, 12009599006321301, 24019198012642603,
        48038396025285205, 96076792050570411, 192153584101140821, 384307168202281641, 768614336404563281,
        1537228672809126563, 3074457345618253125, 6148914691236506251
    };
    return jacob[num];
}

std::vector<int> jacob_order(size_t size)
{
    std::vector<int> order;
    size_t index = 3;
    order.push_back(0);
    order.push_back(1);

    while (true) 
    {
        size_t jacob_value = jacobsthal(index);
        if (jacob_value >= size) break;

        size_t i = jacob_value;
        while (i > jacobsthal(index - 1)) 
        {
            order.push_back(i);
            i--;
        }
        index++;
    }

    return order;
}

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
    // jacob order returns the specially chosen order: 3, 2, 5, 4, ...

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
    T b_sorted;
    typename T::const_iterator a_it = a.begin();

    while (a_it != a.end())
    {
        typename T::iterator b_it = b.begin();
        std::advance(b_it, a_order[*a_it]);
        b_sorted.push_back(*b_it);
        ++a_it;
    }

    b = b_sorted;
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

template void Sorter<std::vector<int> >::PmergeMe(std::vector<int> &nums);
template void Sorter<std::list<int> >::PmergeMe(std::list<int> &nums);
template void Sorter<std::deque<int> >::PmergeMe(std::deque<int> &nums);