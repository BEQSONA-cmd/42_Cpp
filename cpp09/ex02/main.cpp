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

size_t jacobsthal(int n)
{
    size_t jacob_diff[] = 
    {
        2, 2, 6, 10, 22, 42, 86, 170, 342, 682, 1366,
        2730, 5462, 10922, 21846, 43690, 87382, 174762, 349526, 699050,
        1398102, 2796202, 5592406, 11184810, 22369622, 44739242, 89478486,
        178956970, 357913942, 715827882, 1431655766, 2863311530, 5726623062,
        11453246122, 22906492246, 45812984490, 91625968982, 183251937962,
        366503875926, 733007751850, 1466015503702, 2932031007402, 5864062014806,
        11728124029610, 23456248059222, 46912496118442, 93824992236886, 187649984473770,
        375299968947542, 750599937895082, 1501199875790165, 3002399751580331,
        6004799503160661, 12009599006321322, 24019198012642644, 48038396025285288,
        96076792050570576, 192153584101141152, 384307168202282304, 768614336404564608,
        1537228672809129216, 3074457345618258432, 6148914691236516864
    };

    return jacob_diff[n];
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

std::vector<size_t> generate_jacobsthal_sequence(size_t size) {
    std::vector<size_t> jacobsthal = {0, 1}; // Start with the base values
    while (jacobsthal.back() < size) {
        jacobsthal.push_back(2 * jacobsthal[jacobsthal.size() - 1] + jacobsthal[jacobsthal.size() - 2]);
    }
    jacobsthal.pop_back(); // Remove the last value that exceeds the size
    return jacobsthal;
}

// Generate the order of insertion based on Jacobsthal sequence
std::vector<size_t> generate_insertion_order(size_t pend_size) {
    std::vector<size_t> jacobsthal = generate_jacobsthal_sequence(pend_size);
    std::vector<bool> inserted(pend_size, false); // Track inserted indices
    std::vector<size_t> order;

    // Add indices from Jacobsthal sequence
    for (size_t j : jacobsthal) {
        if (j < pend_size && !inserted[j]) {
            order.push_back(j);
            inserted[j] = true;
        }
    }

    // Add remaining indices in natural order
    for (size_t i = 0; i < pend_size; ++i) {
        if (!inserted[i]) {
            order.push_back(i);
        }
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

// Updated binary_insert function with Step 5 integration
void binary_insert(std::vector<int> &main_chain, std::vector<int> &pend) {
    std::vector<size_t> insertion_order = generate_insertion_order(pend.size());

    for (size_t i : insertion_order) {
        int idx = binary_search(main_chain, pend[i], main_chain.size());
        main_chain.insert(main_chain.begin() + idx, pend[i]);
    }
}


void PmergeMe(std::vector<int> &nums)
{
    if (nums.size() <= 1)
        return;

    std::vector<int> a, b;

    group_sort_pairs(nums, a, b);

    PmergeMe(a);

    std::vector<int> main_chain = a;
    std::vector<int> pend = b;

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
