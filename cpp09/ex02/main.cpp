#include "PmergeMe.hpp"

int main(int ac, char **av)
{

    std::vector<int> nums = fill_nums<std::vector<int> >(ac, av);
    std::list<int> list = fill_nums<std::list<int> >(ac, av);
    std::deque<int> deque = fill_nums<std::deque<int> >(ac, av);

    Sorter<std::vector<int> >::PmergeMe(nums);
    Sorter<std::list<int> >::PmergeMe(list);
    Sorter<std::deque<int> >::PmergeMe(deque);

    std::cout << "Sorted: " << std::endl;
    print_nums(nums);
    print_nums(list);
    print_nums(deque);
    std::cout << std::endl;

    return 0;
}
