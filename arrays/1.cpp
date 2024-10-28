#include <unordered_map>
#include <vector>

std::vector<int> twoSum(std::vector<int> &nums, int target)
{
    std::unordered_map<int, int> map;

    for (auto it = nums.begin(); it != nums.end(); it++)
    {
        if (map.find(target - *it) != map.end())
        {
            return std::vector<int>{(int)(it - nums.begin()), map[target - *it]};
        }

        map.insert(std::pair<int, int>(*it, it - nums.begin()));
    }

    return std::vector<int>{-1, -1};
}