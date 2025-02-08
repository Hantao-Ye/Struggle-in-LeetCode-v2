#include <vector>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        path.clear();
        output.clear();

        std::vector<bool> used(nums.size(), false);

        backtrack(nums, used);

        return output;
    }

private:
    vector<vector<int>> output;
    vector<int> path;

    void backtrack(std::vector<int> &nums, std::vector<bool> &used)
    {
        if (path.size() == nums.size())
        {
            output.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (used[i])
            {
                continue;
            }

            path.push_back(nums[i]);
            used[i] = true;
            backtrack(nums, used);
            path.pop_back();
            used[i] = false;
        }
    }
};

int main()
{
    while (true)
    {
        string str;
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
            auto output = s.permute(input);

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