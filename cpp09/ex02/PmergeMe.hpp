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
