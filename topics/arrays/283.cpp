#include <vector>

void moveZeroes(std::vector<int> &nums)
{
    int slow_idx{};

    for (int fast_idx{}; fast_idx < nums.size(); fast_idx++)
    {
        if (nums[fast_idx] == 0)
        {
            continue;
        }

        nums[slow_idx++] = nums[fast_idx];
    }

    for (; slow_idx < nums.size(); slow_idx++)
    {
        nums[slow_idx] = 0;
    }
}