#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

class Solution
{
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int> &nums)
    {
        output.clear();
        path.clear();
        std::sort(nums.begin(), nums.end());
        visited = std::vector<bool>(nums.size(), false);
        backtracking(nums);

        return output;
    }

private:
    std::vector<std::vector<int>> output;
    std::vector<int> path;
    std::vector<bool> visited;

    void backtracking(std::vector<int> &nums)
    {
        if (path.size() == nums.size())
        {
            output.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1] && visited[i - 1] == false)
            {
                continue;
            }

            if (!visited[i])
            {
                visited[i] = true;
                path.push_back(nums[i]);
                backtracking(nums);
                visited[i] = false;
                path.pop_back();
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

        auto output = sol.permuteUnique(input);

        std::cout << '[';
        for (auto const &row : output)
        {
            std::cout << '[';
            for (auto const &col : row)
            {
                std::cout << col;

                if (&col != &row.back())
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