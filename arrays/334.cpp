#include <iostream>
#include <vector>
#include <climits>

class Solution
{
public:
    bool increasingTriplet(std::vector<int> &nums)
    {
        int first_num = INT32_MAX, second_num = INT32_MAX;

        for (int const& num: nums)
        {
            if (num <= first_num)
            {
                first_num = num;
            } else if (num <= second_num)
            {
                second_num = num;
            } else {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    std::vector<int> nums{0, 4, 2, 1, 0, -1, -3};

    Solution sol;
    bool result = sol.increasingTriplet(nums);

    std::cout << result << std::endl;
}