#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &pmergeme)
{
    *this = pmergeme;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &pmergeme)
{
    (void)pmergeme;
    return *this;
}

PmergeMe::~PmergeMe()
{
}
