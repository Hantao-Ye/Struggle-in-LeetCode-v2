#include <vector>
#include <iostream>
#include <sstream>
#include <string>

class Solution
{
public:
    std::vector<std::vector<int>> subsets(std::vector<int> &nums)
    {
        output.clear();
        path.clear();

        output.push_back({});
        backtracking(nums, 0);

        return output;
    }

private:
    void backtracking(std::vector<int> &nums, int index)
    {
        if (index == nums.size())
        {
            return;
        }

        path.push_back(nums[index]);

        output.push_back(path);
        backtracking(nums, index + 1);
        path.pop_back();
        backtracking(nums, index + 1);
    }

    std::vector<std::vector<int>> output;
    std::vector<int> path;
};

int main()
{
    while (true)
    {
        std::string str;
        std::getline(std::cin, str);

        if (str.size() > 0)
        {
            std::istringstream iss(str);

            int val;
            std::vector<int> input;

            while (iss >> val)
            {
                input.push_back(val);
            }

            Solution s{};
            auto output = s.subsets(input);

            for (auto &nums : output)
            {
                std::cout << '[';
                for (auto &num : nums)
                {
                    std::cout << num;

                    if (&num != &nums.back())
                    {
                        std::cout << ',';
                    }
                }

                std::cout << ']';
                if (&nums != &output.back())
                {
                    std::cout << ',';
                }
            }
            std::cout << std::endl;
        }
        else
        {
            break;
        }
    }

    return 0;
}
