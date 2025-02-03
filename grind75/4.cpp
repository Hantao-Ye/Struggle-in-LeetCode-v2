#include <vector>
#include <climits>

class Solution
{
public:
    // full n*2 dp table
    int maxProfit(std::vector<int> &prices)
    {
        int n = prices.size();
        std::vector<std::vector<int>> dp(n, std::vector<int>(2, INT_MIN));

        dp[0][0] = -prices[0];
        dp[0][1] = 0;

        for (int i = 1; i < n; i++)
        {
            dp[i][0] = std::max(-prices[i], dp[i - 1][0]);
            dp[i][1] = std::max(prices[i] + dp[i][0], dp[i - 1][1]);
        }

        return dp[n - 1][1];
    }

    // shrink to 2 state variables
    int maxProfit(std::vector<int> &prices)
    {
        int n = prices.size();

        int min_price = -prices[0];
        int max_profit = 0;

        for (int i = 1; i < n; i++)
        {
            min_price = std::max(min_price, -prices[i]);
            max_profit = std::max(max_profit, prices[i] + min_price);
        }

        return max_profit;
    }
};