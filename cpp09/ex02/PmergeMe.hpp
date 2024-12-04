#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define BLUE "\033[1;34m"
#define CYAN "\033[1;36m"
#define RESET "\033[0m"
#include <iostream>
#include <algorithm>
#include <iterator>
#include <utility>
#include <vector>
#include <list>
#include <deque>
#include <map>

template <typename T>
class Sorter
{
    public:
        typedef typename T::value_type value;
        
        static void PmergeMe(T &nums);
        static void sort_b_on_order(T &a, T &b, std::map<int, value> &a_order);
        static size_t binary_search(T &nums, value value, size_t right_bound);
        static void binary_insert(T &main_chain, T &pend);
        static std::map<int, value> get_map(T &a);
    private:
        Sorter() {};
        ~Sorter() {};
};


#include "Utils.tpp"
#include "PmergeMe.tpp"

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

#endif
