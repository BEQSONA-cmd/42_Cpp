#include "PmergeMe.hpp"

void insertion_sort(std::vector<int> &nums)
{
    for (size_t i = 1; i < nums.size(); i++)
    {
        int key = nums[i];
        int j = i - 1;

        while (key < nums[j] && j >= 0)
        {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = key;
    }
}

void merge_sort(std::vector<int> &nums)
{
    if (nums.size() <= 1)
        return;

    size_t mid = nums.size() / 2;
    std::vector<int> left(nums.begin(), nums.begin() + mid);
    std::vector<int> right(nums.begin() + mid, nums.end());

    merge_sort(left);
    merge_sort(right);

    for (size_t i = 0, j = 0, k = 0; i < nums.size(); i++)
    {
        if (j >= left.size())
            nums[i] = right[k++];
        else if (k >= right.size())
            nums[i] = left[j++];
        else if (left[j] < right[k])
            nums[i] = left[j++];
        else
            nums[i] = right[k++];
    }
}

int binary_search(std::vector<int> &nums, int start_idx, int end_idx, int target)
{
    if (start_idx > end_idx)
        return -1;

    int mid = start_idx + (end_idx - start_idx) / 2;

    if (nums[mid] == target)
        return mid;
    else if (nums[mid] < target)
        return binary_search(nums, mid + 1, end_idx, target);
    else
        return binary_search(nums, start_idx, mid - 1, target);
}


int binary_search(std::vector<int> &nums, int value)
{
    size_t left = 0;
    size_t right = nums.size();

    while (left < right)
    {
        size_t mid = left + (right - left) / 2;
        if (nums[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}