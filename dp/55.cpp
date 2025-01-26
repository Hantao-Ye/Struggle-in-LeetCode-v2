#include <vector>

class Solution
{
public:
    bool canJump(std::vector<int> &nums)
    {
        int n = nums.size();

        std::vector<bool> dp(n, false);
        dp[n - 1] = true;

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = i + 1; j <= std::min(n - 1, i + nums[i]); j++)
            {
                if (dp[j])
                {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[0];
    }

    bool canJumpGreedy(std::vector<int> &nums)
    {
        int n = nums.size();
        int last_idx = n - 1;
        for (int i = last_idx; i >= 0; i--)
        {
            if (i + nums[i] >= last_idx)
            {
                last_idx = i;
            }
        }

        return last_idx == 0;
    }
};