#include <vector>
#include <unordered_map>

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        std::unordered_map<int, std::size_t> visited;

        for (std::size_t i = 0; const auto &num : nums)
        {
            if (auto it = visited.find(target - num); it != visited.end())
            {
                return {static_cast<int>(it->second), static_cast<int>(i)};
            }
            visited[num] = i++;
        }

        return {-1, -1};
    }
};