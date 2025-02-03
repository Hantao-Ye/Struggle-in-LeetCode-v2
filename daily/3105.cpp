#include <vector>

using namespace std;

class Solution
{
public:
    int longestMonotonicSubarray(vector<int> &nums)
    {
        int size = 1;
        int increase_left = 0, decrease_left = 0;
        for (int right = 1; right < nums.size(); right++)
        {
            if (nums[right] > nums[right - 1])
            {
                size = max(size, right - increase_left + 1);
            }
            else
            {
                increase_left = right;
            }

            if (nums[right] < nums[right - 1])
            {
                size = max(size, right - decrease_left + 1);
            }
            else
            {
                decrease_left = right;
            }
        }

        return size;
    }
};