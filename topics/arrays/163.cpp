#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Solution
{
public:
    std::vector<std::vector<int>> findMissingRanges(std::vector<int> &nums, int lower, int upper)
    {
        std::vector<std::vector<int>> output;
        int idx = 0;

        while (lower <= upper && idx < nums.size())
        {
            if (nums[idx] > lower)
            {
                output.push_back({lower, nums[idx] - 1});
            }
            lower = nums[idx++] + 1;
        }

        if (lower <= upper)
        {
            output.push_back({lower, upper});
        }

        return output;
    }
};

int main()
{
    Solution sol;
    std::string line;
    while (true)
    {
        std::getline(std::cin, line);

        if (line.size() == 0)
        {
            break;
        }

        std::istringstream iss(line);

        int val;
        std::vector<int> input;

        while (iss >> val)
        {
            input.push_back(val);
        }

        std::getline(std::cin, line);
        int lower = std::stoi(line);
        std::getline(std::cin, line);
        int upper = std::stoi(line);

        std::vector<std::vector<int>> output;
        output = sol.findMissingRanges(input, lower, upper);

        std::cout << '[';
        for (auto const& row: output)
        {
            std::cout << '[';
            for (auto const& num: row)
            {
                std::cout << num;

                if (&num != &row.back())
                {
                    std::cout << ',';
                }
            }
            std::cout << ']';

            if (&row != &output.back())
            {
                std::cout << ',';
            }
        }
        std::cout << ']' << std::endl;

    }

    return 0;
}