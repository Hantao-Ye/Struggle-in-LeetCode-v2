#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int minMaxSums(vector<int> &nums, int k)
    {
        const int MOD = 1e9 + 7;

        long long output = 0;
        sort(nums.begin(), nums.end());

        for (int num : nums)
        {
            output = (output + 2LL * num) % MOD;
        }

        for (int length = 2; length <= k; length++)
        {
            for (int i = 0; i < nums.size(); i++)
            {
                for (int j = i + length - 1; j < nums.size(); j++)
                {
                    int size = j - i - 1;
                    if (size >= length - 2)
                    {
                        output = (output + nums[i] + nums[j]) % MOD;
                    }
                }
            }
        }

        return output;
    }
};

int main()
{
    Solution sol;

    std::vector<int> nums{10, 5, 9, 9, 10, 10, 7, 7, 9, 6, 9, 6, 7, 6, 4, 9, 8, 4, 2, 0, 0, 3, 9, 3, 10, 3, 1, 9, 8, 2, 8, 2, 0, 7, 7, 6, 4, 6, 7, 3, 2, 5, 6, 6, 5, 0, 5, 7, 8, 1};
    int k = 29;

    std::cout << sol.minMaxSums(nums, k) << std::endl;
}