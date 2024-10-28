#include <iostream>
#include <unordered_set>
#include <vector>

int removeDuplicates(std::vector<int> &nums)
{
    if (nums.size() <= 1)
    {
        return nums.size();
    }

    int slow_idx{};

    for (int fast_idx = 0; fast_idx < nums.size(); fast_idx++)
    {
        if (nums[fast_idx] != nums[slow_idx])
        {
            nums[++slow_idx] = nums[fast_idx];
        }
    }

    return slow_idx + 1;
}

int main()
{
    std::vector<int> nums{1, 1, 1, 2, 2, 2, 3, 3};
    std::cout << removeDuplicates(nums) << std::endl;
    std::cout << "=========" << std::endl;
    for (auto it = nums.begin(); it != nums.end(); it++)
    {
        std::cout << *it << std::endl;
    }
}