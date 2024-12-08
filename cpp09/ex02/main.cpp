#include "PmergeMe.hpp"
#include <ctime>

template <typename T>
void timetest(T &nums)
{
    std::clock_t start = std::clock();
    
    Sorter<T>::PmergeMe(nums);
    
    std::clock_t end = std::clock();
    double duration = 1000000 * (end - start) / CLOCKS_PER_SEC;
    duration /= 100;
    
    std::cout << "Sort time: " << duration << " us" << std::endl;
}

int main(int ac, char **av)
{
    if(Error(ac, av))
        return 1;

    std::vector<int> vector = fill_nums<std::vector<int> >(ac, av);
    std::list<int> list = fill_nums<std::list<int> >(ac, av);
    std::deque<int> deque = fill_nums<std::deque<int> >(ac, av);
    
    std::cout << "Unsorted: "; print_nums(vector);
    timetest(vector);
    timetest(list);
    timetest(deque);
    std::cout << "Sorted: "; print_nums(vector);

    return 0;
}