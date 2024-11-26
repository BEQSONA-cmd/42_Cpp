#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    if (ac != 3)
    {
        std::cerr << "Usage: ./pmergeMe file1 file2" << std::endl;
        return 1;
    }
    // PmergeMe pmergeMe(av[1], av[2]);
    // pmergeMe.merge();
    return 0;
}
