#include <vector>
#include <iostream>
#include <sstream>

class Solution
{
public:
    int maxSubArray(std::vector<int> &nums)
    {
        int n = nums.size();
        std::vector<int> current_array(n);
        std::vector<int> max_array(n);

        current_array[0] = nums[0];
        max_array[0] = nums[0];

        for (int i = 1; i < n; i++)
        {
            current_array[i] = std::max(nums[i], current_array[i - 1] + nums[i]);
            max_array[i] = std::max(max_array[i - 1], current_array[i]);
        }

        return max_array.back();
    }
};

int main()
{
    Solution s{};

    while (true)
    {
        std::string str{};
        std::getline(std::cin, str);

        if (str.size() < 1)
            break;

        int val(0);
        std::istringstream iss(str);
        std::vector<int> nums{};

        while (iss >> val)
        {
            nums.push_back(val);
        }

        std::cout << s.maxSubArray(nums) << std::endl;
    }

    return 0;
}