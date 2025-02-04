#include <vector>

class Solution
{
public:
    int maxAscendingSum(std::vector<int> &nums)
    {
        int sum = nums.front();
        int current_sum = sum;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i - 1])
            {
                current_sum += nums[i];
            }
            else
            {
                current_sum = nums[i];
            }
            sum = std::max(sum, current_sum);
        }

        return sum;
    }
};