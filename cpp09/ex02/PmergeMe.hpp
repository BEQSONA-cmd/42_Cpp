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

extern size_t comparisons;

template <typename T>
class Sorter
{
    private:
        Sorter() {};
        ~Sorter() {};
    public:
        typedef typename T::value_type value;
        
        static void group_sort_pairs(T &nums, T &a, T &b);

        static std::map<int, value> get_map(T &a);

        static void PmergeMe(T &nums);

        static void sort_b_on_order(T &a, T &b, std::map<int, value> &a_order);

        static void create_main_and_pend(T &a, T &b, T &main_chain, T &pend);
        
        static void binary_insert(T &main_chain, T &pend);
};


#include "Utils.tpp"
#include "PmergeMe.tpp"

#endif
