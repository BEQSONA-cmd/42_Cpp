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

void init(std::vector<int> &num_vector, char **av);
void print(std::vector<int> nums);
int jacobsthal(int n);
void print_pairs(std::vector<std::pair<int, int > > &pairs);
void swap_pairs(std::vector<std::pair<int, int> > &pairs);
std::vector<std::pair<int, int> > create_pairs(std::vector<int> &nums);

#endif
