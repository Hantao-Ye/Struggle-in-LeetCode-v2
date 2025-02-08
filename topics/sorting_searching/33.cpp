#include <vector>
#include <iostream>

class Solution
{
public:
    int search(std::vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1, mid;

        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }

            if (nums[mid] >= nums[low])
            {
                if (target < nums[mid] && target >= nums[low])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            else
            {
                if (target > nums[mid] && target <= nums[high])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }

        return -1;
    }
};