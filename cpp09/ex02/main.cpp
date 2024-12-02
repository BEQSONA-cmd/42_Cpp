#include "PmergeMe.hpp"

int comparison = 0;

void group_sort_pairs(std::vector<int> &nums, std::vector<int> &a, std::vector<int> &b)
{
    size_t i = 0;
    while (i < nums.size() - 1)
    {
        comparison++;
        if (nums[i] < nums[i + 1])
        {
            a.push_back(nums[i + 1]);
            b.push_back(nums[i]);
        }
        else
        {
            a.push_back(nums[i]);
            b.push_back(nums[i + 1]);
        }
        i += 2;
    }
    if (i < nums.size())
        a.push_back(nums[i]);
}

void create_main_chain(std::vector<int> &a, std::vector<int> &b, std::vector<int> &main_chain, std::vector<int> &pend)
{
    main_chain.push_back(b[0]);
    size_t i = 0;
    while (i < a.size())
    {
        main_chain.push_back(a[i]);
        i++;
    }
    i = 1;
    while (i < b.size())
    {
        pend.push_back(b[i]);
        i++;
    }
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

int binary_search(std::vector<int> &nums, int value, size_t right_bound) 
{
    size_t left = 0;
    size_t right = right_bound;

    while (left < right) 
    {
        comparison++;
        size_t mid = left + (right - left) / 2;

        if (nums[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

void binary_insert(std::vector<int> &main_chain, std::vector<int> &pend) 
{
    std::vector<int> order = jacob_order(pend.size());

    std::vector<int> used_nums;

    for (size_t i = 0; i < order.size(); i++) 
    {
        size_t index = binary_search(main_chain, pend[i], main_chain.size());
        main_chain.insert(main_chain.begin() + index, pend[i]);

        used_nums.push_back(pend[i]);
    }


    for (size_t i = 0; i < pend.size(); i++) 
    {
        if (std::find(used_nums.begin(), used_nums.end(), pend[i]) == used_nums.end()) 
        {
            main_chain.push_back(pend[i]);
        }
    }

}

void PmergeMe(std::vector<int> &nums)
{
    if (nums.size() <= 1)
        return;

    std::vector<int> a, b;

    group_sort_pairs(nums, a, b);

    PmergeMe(a);

    std::vector<int> main_chain;
    std::vector<int> pend;

    create_main_chain(a, b, main_chain, pend);

    binary_insert(main_chain, pend);

    nums = main_chain;
}

int main(int ac, char **av)
{
    int i = 1;
    int arr[ac - 1];

    while (i < ac)
    {
        arr[i - 1] = std::atoi(av[i]);
        i++;
    }

    std::vector<int> nums;
    for (int i = 1; i < ac; i++)
        nums.push_back(arr[i - 1]);

    bool has_stragler = false;
    int stragler = 0;
    if(nums.size() % 2 != 0)
    {
        has_stragler = true;
        stragler = nums[nums.size() - 1];
        nums.pop_back();
    }
    (void)ac;
    (void)av;
    (void)has_stragler;
    (void)stragler;

    PmergeMe(nums);
    std::cout << "Sorted array: " << std::endl;
    print(nums);
    std::cout << std::endl;

    std::cout << "Number of comparisons: " << comparison << std::endl;

    return 0;
}
