#include <vector>

class Solution
{
public:
    int maxProfit(std::vector<int> &prices)
    {
        std::vector<std::vector<int>> dp(prices.size(), std::vector<int>(2, 0));
        dp[0][0] = -prices[0];

        for (size_t i = 1; i < prices.size(); i++)
        {
            dp[i][0] = std::max(-prices[i], dp[i - 1][0]);
            dp[i][1] = std::max(dp[i - 1][1], prices[i] + dp[i][0]);
        }

        return dp[prices.size() - 1][1];

        // if it is not dp
        // keep finding the minimum while updating the maximum profit
    }
};