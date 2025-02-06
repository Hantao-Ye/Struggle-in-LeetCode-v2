#include <vector>
#include <unordered_map>

class Solution {
public:
    int tupleSameProduct(std::vector<int>& nums) {
        if (nums.size() < 4)
        {
            return 0;
        }

        std::unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                int result = nums[i] * nums[j];

                map[result]++;
            }
        }

        int result = 0;

        for (auto it = map.begin(); it != map.end(); it++)
        {
            int size = it->second;
            if (size >= 2)
            {
                result += size * (size - 1) * 4;
            }
        }

        return result;
    }
};