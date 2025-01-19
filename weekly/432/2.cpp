#include <vector>
#include <climits>
#include <iostream>

using namespace std;

class Solution
{
public:
    int maximumAmount(vector<vector<int>> &coins)
    {
        int m = coins.size(), n = coins[0].size();
        std::vector<std::vector<std::vector<int>>> dp(m, std::vector<std::vector<int>>(n, std::vector<int>(3, INT_MIN)));

        for (int k = 0; k < 3; k++)
        {
            dp[0][0][k] = coins[0][0] >= 0 ? coins[0][0] : k > 0 ? 0 : coins[0][0];
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                {
                    continue;
                }

                for (int k = 0; k < 3; k++)
                {
                    if (j > 0)
                    {
                        int val = dp[i][j - 1][k] + coins[i][j];

                        if (k > 0 && coins[i][j] < 0)
                        {
                            val = max(val, dp[i][j - 1][k - 1]);
                        }

                        dp[i][j][k] = max(val, dp[i][j][k]);
                    }

                    if (i > 0)
                    {
                        int val = dp[i - 1][j][k] + coins[i][j];

                        if (k > 0 && coins[i][j] < 0)
                        {
                            val = max(val, dp[i - 1][j][k - 1]);
                        }
                        
                        dp[i][j][k] = max(val, dp[i][j][k]);
                    }
                }
            }
        }

        return max(dp[m - 1][n - 1][0], max(dp[m - 1][n - 1][1], dp[m - 1][n - 1][2]));
    }
};

int main()
{
    // vector<vector<int>> coins = {{-7, 12, 12, 13}, {-6, 19, 19, -6}, {9, -2, -10, 16}, {-4, 14, -10, -9}};
    vector<vector<int>> coins = {{0,1,-1},{1,-2,3},{2,-3,4}};
    // vector<vector<int>> coins = {{10, 10, 10}, {10, 10, 10}};

    Solution s;
    int result = s.maximumAmount(coins);

    std::cout << result << std::endl;

    return 0;
}