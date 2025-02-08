#include <iostream>
#include <vector>
#include <sstream>

class Solution
{
public:
    void sortColors(std::vector<int> &nums)
    {
        int slow_idx = 0, fast_idx = nums.size() - 1;
        int idx = 0;

        while (idx <= fast_idx)
        {
            if (nums[idx] == 0)
            {
                std::swap(nums[slow_idx++], nums[idx++]);
            }
            else if (nums[idx] == 2)
            {
                std::swap(nums[fast_idx--], nums[idx]);
            }
            else
            {
                idx++;
            }
        }
    }
};

int main()
{
    std::string str;
    Solution sol;

    while (true)
    {
        std::getline(std::cin, str);
        if (str.size() < 1)
        {
            break;
        }

        std::istringstream iss(str);

        int val;
        std::vector<int> input;

        while (iss >> val)
        {
            input.push_back(val);
        }

        sol.sortColors(input);

        std::cout << '[';
        for (auto const &val : input)
        {
            std::cout << val;

            if (&val != &input.back())
            {
                std::cout << ',';
            }
        }
        std::cout << ']' << std::endl;
    }

    return 0;
}