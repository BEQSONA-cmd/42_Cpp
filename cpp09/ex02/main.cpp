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

void binary_insert(std::vector<int> &a, int value)
{
    size_t left = 0;
    size_t right = a.size();

    // if (a.empty() || value <= a[0])
    // {
    //     a.insert(a.begin(), value);
    //     return;
    // }
    // else if (value >= a[a.size() - 1])
    // {
    //     a.push_back(value);
    //     return;
    // }

    while (left < right)
    {
        comparison++;
        size_t mid = left + (right - left) / 2;
        if (a[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }
    a.insert(a.begin() + left, value);
}

void Insert_elements(std::vector<int> &a, const std::vector<int> &b)
{
    size_t i = 0;
    while (i < b.size())
    {
        binary_insert(a, b[i]);
        i++;
    }
}

void PmergeMe(std::vector<int> &nums)
{
    if (nums.size() <= 1)
        return;

    std::vector<int> a, b;

    print_pairs(nums);
    std::cout << std::endl;
    group_sort_pairs(nums, a, b);

    PmergeMe(a);

    Insert_elements(a, b);
    print_pairs(a);
    std::cout << std::endl;

    nums = a;
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
    // print(nums);

    std::cout << "Number of comparisons: " << comparison << std::endl;

    return 0;
}
