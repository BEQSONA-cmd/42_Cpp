#include "PmergeMe.hpp"

template <typename T>
T fill_nums(int ac, char **av)
{
    int i = 1;
    int arr[ac - 1];
    T nums;

    while (i < ac)
    {
        arr[i - 1] = std::atoi(av[i]);
        i++;
    }
    
    i = 1;
    while (i < ac)
    {
        nums.push_back(arr[i - 1]);
        i++;
    }

    return nums;
}

template <typename T>
void print_nums(T nums)
{
    typename T::iterator it = nums.begin();
    while (it != nums.end())
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
}

size_t jacobsthal(size_t num)
{
    size_t jacob[] = 
    {
        0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461,
        10923, 21845, 43691, 87381, 174763, 349525, 699051, 1398101, 2796203,
        5592405, 11184811, 22369621, 44739243, 89478485, 178956971, 357913941,
        715827883, 1431655765, 2863311531, 5726623061, 11453246123, 22906492245,
        45812984491, 91625968981, 183251937963, 366503875925, 733007751851,
        1466015503701, 2932031007403, 5864062014805, 11728124029611, 23456248059221,
        46912496118443, 93824992236885, 187649984473771, 375299968947541, 750599937895081,
        1501199875790163, 3002399751580325, 6004799503160651, 12009599006321301, 24019198012642603,
        48038396025285205, 96076792050570411, 192153584101140821, 384307168202281641, 768614336404563281,
        1537228672809126563, 3074457345618253125, 6148914691236506251
    };
    return jacob[num];
}

std::vector<int> jacob_order(size_t size)
{
    std::vector<int> order;
    size_t index = 3;
    order.push_back(0);
    order.push_back(1);

    while (true) 
    {
        size_t jacob_value = jacobsthal(index);
        if (jacob_value >= size) break;

        size_t i = jacob_value;
        while (i > jacobsthal(index - 1)) 
        {
            order.push_back(i);
            i--;
        }
        index++;
    }

    return order;
}

// size_t binary_serch(std::vector<int> nums, int value, size_t right_bound)
// {
//     size_t left = 0;
//     size_t right = right_bound;

//     while (left < right)
//     {
//         size_t mid = left + (right - left) / 2;

//         if (nums[mid] < value)
//             left = mid + 1;
//         else
//             right = mid;
//     }

//     return left;
// }

template <typename T>
size_t binary_search(T &nums, typename T::value_type value, size_t right_bound)
{
    typename T::iterator left = nums.begin();
    typename T::iterator right = nums.begin();

    // size_t i = 0;
    // while (i < right_bound)
    // {
    //     ++right;
    //     ++i;
    // }

    size_t pos = 0;
    std::advance(right, right_bound);

    while (left != right)
    {
        comparisons++;
        typename T::iterator mid = left;
        pos = std::distance(left, right) / 2;
        std::advance(mid, pos);

        if (*mid < value)
            left = ++mid;
        else
            right = mid;
    }
    
    pos = std::distance(nums.begin(), left);
    return pos;
}
