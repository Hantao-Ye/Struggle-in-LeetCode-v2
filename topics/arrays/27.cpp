#include <iostream>
#include <sstream>
#include <vector>

class Solution
{
public:
    int removeElement(std::vector<int> &nums, int val)
    {
        int slow_idx = 0;

        for (int fast_idx = 0; slow_idx < nums.size() && fast_idx < nums.size(); fast_idx++)
        {
            if (nums[fast_idx] == val)
            {
                continue;
            }
            else
            {
                nums[slow_idx++] = nums[fast_idx];
            }
        }

        return slow_idx;
    }
};

int main()
{
    Solution s{};

    while (true)
    {
        std::string str{};
        std::getline(std::cin, str);

        if (str.size() == 0)
        {
            break;
        }

        int val(0);
        std::istringstream iss(str);

        std::vector<int> nums{};

        while (iss >> val)
        {
            nums.push_back(val);
        }

        std::string second_line;
        std::getline(std::cin, second_line);
        std::istringstream iss2(second_line);
        iss2 >> val;

        int k = s.removeElement(nums, val);

        str.clear();

        for (size_t i = 0; i < k; i++)
        {
            str += std::to_string(nums[i]);
            str.push_back(' ');
        }

        str.pop_back();

        std::cout << str << std::endl;
    }

    return 0;
}