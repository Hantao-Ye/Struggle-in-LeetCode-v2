#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool check(vector<int> &nums)
    {
        auto it = min_element(nums.begin(), nums.end());
        int smallest_index = it - nums.begin();

        int smallest = nums[smallest_index], greatest, greatest_index;
        if (smallest_index == 0)
        {
            while (nums.size() > 1 && nums.back() == smallest)
            {
                nums.pop_back();
            }
            greatest = nums.back();
            greatest_index = nums.size() - 1;
        }
        else
        {
            greatest = nums[smallest_index - 1];
            greatest_index = smallest_index - 1;
        }

        int left = greatest_index, right = smallest_index;
        if (right != 0)
        {
            if (nums.front() < nums.back())
            {
                return false;
            }
        }

        while (left >= 1)
        {
            if (nums[left] < smallest || nums[left] > greatest || nums[left] < nums[left - 1])
            {
                return false;
            }

            left--;
        }
        while (right < nums.size() - 1)
        {
            if (nums[right] > greatest || nums[right] < smallest || nums[right] > nums[right + 1])
            {
                return false;
            }

            right++;
        }

        return true;
    }
};

int main()
{
    Solution sol;
    vector<int> nums{1, 2, 3};

    std::cout << sol.check(nums) << std::endl;
}