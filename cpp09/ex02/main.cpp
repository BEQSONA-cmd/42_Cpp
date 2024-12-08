#include "PmergeMe.hpp"

template <typename T>
void timetest(T &nums, std::string type)
{
    std::clock_t start = std::clock();
    Sorter<T>::PmergeMe(nums);
    std::clock_t end = std::clock();

    double duration = 1000000 * (end - start) / CLOCKS_PER_SEC;
    duration /= 100;
    
    std::cout << nums.size() << " elements with "<< type << ": " << duration << " us" << std::endl;
}

int main(int ac, char **av)
{
    if(Error(ac, av))
        return 1;

    std::vector<int> sort = fill_nums<std::vector<int> >(ac, av);
    std::cout << "Before: "; print_nums(sort);
    Sorter<std::vector<int> >::PmergeMe(sort);
    std::cout << "After: "; print_nums(sort);

    std::vector<int> vector = fill_nums<std::vector<int> >(ac, av);
    std::list<int> list = fill_nums<std::list<int> >(ac, av);
    std::deque<int> deque = fill_nums<std::deque<int> >(ac, av);
    
    timetest(vector , "Vector");
    timetest(list , "List");
    timetest(deque , "Deque");

    return 0;
}