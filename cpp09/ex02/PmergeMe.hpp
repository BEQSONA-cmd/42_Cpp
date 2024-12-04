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
#include <set>
#include <map>
#include <stack>


void print_pairs(std::vector<int> a);
size_t jacobsthal(int n);
bool has_double(std::vector<int> &nums);

#include "PmergeMe.tpp"

#endif
