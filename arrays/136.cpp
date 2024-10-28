#include <vector>
#include <unordered_set>

int singleNumber(std::vector<int> &nums)
{
    int res = nums[0];

    for (int idx = 1; idx < nums.size(); idx++)
    {
        res ^= nums[idx];
    }

    return res;
}