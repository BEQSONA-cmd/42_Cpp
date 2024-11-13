#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

template <typename T>
void fill_container(T &container, const int &size)
{
    int i = 2;
    int j = 0;
    while(j < size)
    {
        container.push_back(i);
        i++;
        j++;
    }
}

int main(void)
{
    std::vector<int> vector;
    std::list<int> list;
    std::deque<int> deque;

    fill_container(vector, 10);
    fill_container(list, 10);
    fill_container(deque, 10);

    try
    {
        easyfind(vector, 5);
        easyfind(list, 5);
        easyfind(deque, 5);
        easyfind(vector, 15);
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return(0);
}
