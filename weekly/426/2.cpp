#include <vector>
#include <numeric>
#include <unordered_map>
#include <climits>

class Solution
{
public:
    int getLargestOutlier(std::vector<int> &nums)
    {
        int sum = 0;
        std::unordered_map<int, int> map{};

        for (auto &num : nums)
        {
            sum += num;
            if (map.find(num) == map.end())
            {
                map.insert(std::pair<int, int>{num, 1});
            }
            else
            {
                map[num]++;
            }
        }

        int outlier = INT_MIN;

        for (auto &num : nums)
        {
            int new_sum = sum - 2 * num;

            if (map.find(new_sum) != map.end() && (new_sum != num || (new_sum == num && map[new_sum] > 1)))
            {
                outlier = std::max(outlier, new_sum);
            }
        }

        return outlier;
    }
};