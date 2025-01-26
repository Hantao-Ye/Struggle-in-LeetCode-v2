#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int countPartitions(vector<int> &nums)
    {
        int count = 0;
        int sum = 0;

        for (int const &num : nums)
        {
            sum += num;
        }

        int left_sum = nums[0], right_sum = sum - nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            int diff = abs(left_sum - right_sum);
            if (diff % 2 == 0)
            {
                count++;
            }

            left_sum += nums[i];
            right_sum -= nums[i];
        }

        return count;
    }
};
