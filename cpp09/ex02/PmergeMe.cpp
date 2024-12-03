#include "PmergeMe.hpp"

void print(std::vector<int> nums)
{
    size_t i = 0;
    while(i < nums.size())
    {
        std::cout << nums[i] << " ";
        i++;
    }
    std::cout << std::endl;
}

void print_pairs(std::vector<int> a)
{
    size_t i = 0;
    if(a.size() == 0)
        return;
    if(a.size() == 1)
    {
        std::cout << "[ " << a[0] << " ]";
        return;
    }

    if(a.size() % 2 != 0)
    {
        std::cout << "[ " << a[0] << " ]";
        i++;
    }
    while(i < a.size())
    {
        std::cout << "[ " << a[i] << ", " << a[i + 1] << " ]";
        i += 2;
    }
}

bool has_double(std::vector<int> &nums)
{
    for (size_t i = 0; i < nums.size(); i++)
    {
        for (size_t j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] == nums[j])
                return true;
        }
    }
    return false;
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

bool is_jacobsthal(size_t num)
{
    size_t i = 3;
    while (true) 
    {
        size_t jacob_value = jacobsthal(i);
        if (jacob_value == num) return true;
        if (jacob_value > num) return false;
        i++;
    }
}
