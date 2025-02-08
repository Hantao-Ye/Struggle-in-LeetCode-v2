#include <vector>
#include <iostream>
#include <sstream>

class Solution
{
public:
    int removeDuplicates(std::vector<int> &nums)
    {
        int slow_idx = 0, fast_idx = 0;

        while (slow_idx < nums.size() && fast_idx < nums.size())
        {
            int first_fast_idx = fast_idx;
            int first_slow_idx = slow_idx;
            while (fast_idx < nums.size() && nums[first_fast_idx] == nums[fast_idx])
            {
                fast_idx++;
            }

            int repeated_size = std::min(2, fast_idx - first_fast_idx);
            for (; slow_idx < first_slow_idx + repeated_size && slow_idx < nums.size(); slow_idx++)
            {
                nums[slow_idx] = nums[first_fast_idx];
            }

            if (slow_idx < nums.size() && fast_idx < nums.size())
            {
                nums[slow_idx] = nums[fast_idx];
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

        int val(0);
        std::istringstream iss(str);
        std::vector<int> input{};

        while (iss >> val)
        {
            input.push_back(val);
        }

        str.clear();
        int k = s.removeDuplicates(input);

        for (int i = 0; i < k; i++)
        {
            str += std::to_string(input[i]);
            str += " ";
        }

        str.pop_back();
        std::cout << str << std::endl;
    }

    return 0;
}