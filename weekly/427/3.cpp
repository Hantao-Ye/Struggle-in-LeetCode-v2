#include <vector>
#include <deque>
#include <iostream>
#include <climits>

using namespace std;

class Solution
{
public:
    long long maxSubarraySum(vector<int> &nums, int k)
    {
        std::vector<long long> prefix_sum(1);

        for (auto num : nums)
        {
            prefix_sum.push_back(prefix_sum.back() + num);
        }

        long long max_sum = LLONG_MIN;
        for (int i = 0; i < k; i++)
        {
            long long current_sum = 0;
            for (int j = i; j + k <= nums.size(); j += k)
            {
                long long prefix_sum_part = prefix_sum[j + k] - prefix_sum[j];
                current_sum = max(prefix_sum_part, current_sum + prefix_sum_part);
                max_sum = max(max_sum, current_sum);
            }
        }

        return max_sum;
    }
};

int main()
{
    vector<int> nums = {1, 2};

    Solution s{};

    s.maxSubarraySum(nums, 1);
}