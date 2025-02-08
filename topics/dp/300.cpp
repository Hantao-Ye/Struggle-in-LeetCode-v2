#include <vector>

using namespace std;

class Solution
{
public:
    int lengthOfLIS_DP(vector<int> &nums)
    {
        vector<int> dp(nums.size(), 1);

        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        int size = 1;
        for (int val : dp)
        {
            size = max(size, val);
        }

        return size;
    }

    int lengthOfLIS_Binary(vector<int> &nums)
    {
        vector<int> subsequence;
        subsequence.reserve(nums.size());

        size_t size = 1;
        subsequence.push_back(nums[0]);

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > subsequence.back())
            {
                subsequence.push_back(nums[i]);
            }
            else
            {
                int j = find(subsequence, nums[i]);
                subsequence[j] = nums[i];
            }

            size = max(size, subsequence.size());
        }

        return (int)size;
    }

    int find(vector<int> &subsequence, int val)
    {
        int low = 0, high = subsequence.size() - 1, mid;

        while (low <= high)
        {
            mid = low + (high - low) / 2;

            if (val < subsequence[mid])
            {
                high = mid - 1;
            }
            else if (val > subsequence[mid])
            {
                low = mid + 1;
            }
            else
            {
                return mid;
            }
        }

        return low;
    }
};