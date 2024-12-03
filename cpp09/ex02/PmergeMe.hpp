#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define BLUE "\033[1;34m"
#define CYAN "\033[1;36m"
#define RESET "\033[0m"
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <list>
#include <deque>

void print_nums(std::vector<int> nums);
void print_nums(std::list<int> nums);

void print_pairs(std::vector<int> a);
size_t jacobsthal(int n);
bool has_double(std::vector<int> &nums);

#endif
