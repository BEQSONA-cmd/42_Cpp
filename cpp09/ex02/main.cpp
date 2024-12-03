#include "PmergeMe.hpp"

int comparison = 0;

void group_sort_pairs(std::vector<int> &nums, std::vector<int> &a, std::vector<int> &b)
{
    size_t i = 0;
    while (i + 1 < nums.size()) 
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

    // Debugging output
    std::cout << "a: ";
    for (auto v : a) std::cout << v << " ";
    std::cout << std::endl;
    std::cout << "b: ";
    for (auto v : b) std::cout << v << " ";
    std::cout << std::endl;
}

void create_main_chain(std::vector<int> &a, std::vector<int> &b, std::vector<int> &main_chain, std::vector<int> &pend)
{
    if (!b.empty())
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

    // Debugging output
    std::cout << "main_chain: ";
    for (auto v : main_chain) std::cout << v << " ";
    std::cout << std::endl;
    std::cout << "pend: ";
    for (auto v : pend) std::cout << v << " ";
    std::cout << std::endl;
    
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
    for (size_t i = 0; i < pend.size(); i++)
    {
        size_t index = binary_search(main_chain, pend[i], main_chain.size());
        main_chain.insert(main_chain.begin() + index, pend[i]);
    }
}
void PmergeMe(std::vector<int> &nums)
{
    if (nums.size() <= 1)
        return;
    bool has_stragler = false;
    int stragler = 0;
    if(nums.size() % 2 != 0)
    {
        has_stragler = true;
        stragler = nums[nums.size() - 1];
        nums.pop_back();
    }

    std::vector<int> a, b;

    group_sort_pairs(nums, a, b);

    PmergeMe(a);

    std::vector<int> main_chain;
    std::vector<int> pend;

    create_main_chain(a, b, main_chain, pend);

    if(has_stragler)
        pend.push_back(stragler);
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

    PmergeMe(nums);
    std::cout << "Sorted array: " << std::endl;
    print(nums);
    std::cout << std::endl;

    if(has_double(nums))
        std::cout << "Array has duplicates" << std::endl;

    std::cout << "Number of comparisons: " << comparison << std::endl;

    return 0;
}
