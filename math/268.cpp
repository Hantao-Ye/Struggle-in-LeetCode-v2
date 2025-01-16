#include <vector>

class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        int count = 0;

        for (int const& num: nums)
        {
            count += num;
        }

        return nums.size() * (nums.size() + 1) / 2 - count;
    }
};