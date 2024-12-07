#include <vector>

class Solution
{
public:
    int rob(std::vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;

        std::vector<int> dp(nums.size());
        dp[0] = nums[0];

        if (nums.size() > 1)
            dp[1] = std::max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); i++)
        {
            dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp.back();
    }
};