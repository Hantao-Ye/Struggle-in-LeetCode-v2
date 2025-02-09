#include <unordered_map>
#include <vector>

class Solution
{
public:
    long long countBadPairs(std::vector<int> &nums)
    {
        std::unordered_map<int, long long> count_map;
        long long n = nums.size();

        for (int i = 0; i < n; i++)
        {
            count_map[nums[i] - i]++;
        }

        long long ans = n * (n - 1) / 2;

        for (auto it = count_map.begin(); it != count_map.end(); it++)
        {
            ans -= (it->second) * (it->second - 1) / 2;
        }

        return ans;
    }
};