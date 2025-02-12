#include <vector>

class Solution
{
public:
    int majorityElement(std::vector<int> &nums)
    {
        int candidate = nums[0];
        int count = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == candidate)
            {
                count++;
            }
            else if (count > 0)
            {
                count--;
            }
            else if (count == 0)
            {
                candidate = nums[i];
                count = 1;
            }
        }

        return candidate;
    }
};