#include <iostream>
#include <sstream>
#include <vector>

class Solution
{
public:
    std::vector<std::string> generateParenthesis(int n)
    {
        if (n <= 0)
        {
            return {};
        }

        str.clear();
        result.clear();

        backtracking(0, 0, n);

        return result;
    }

    void backtracking(int complete, int incomplete, int n)
    {
        if (complete == n)
        {
            result.push_back(str);
            return;
        }

        if (complete < n && incomplete < n && complete + incomplete < n)
        {
            str.push_back('(');
            backtracking(complete, incomplete + 1, n);
            str.pop_back();
        }

        if (incomplete > 0)
        {
            str.push_back(')');
            backtracking(complete + 1, incomplete - 1, n);
            str.pop_back();
        }
    }

private:
    std::string str;
    std::vector<std::string> result;
};

int main()
{
    Solution s{};
    while (true)
    {
        std::string line;
        std::getline(std::cin, line);

        if (line.size() < 1)
        {
            break;
        }

        int val(0);
        std::istringstream iss(line);

        while (iss >> val)
        {
            auto result = s.generateParenthesis(val);

            std::cout << '[';
            for (const auto &combination : result)
            {
                std::cout << combination;
                if (&combination != &result.back())
                {
                    std::cout << ", ";
                }
            }
            std::cout << ']' << std::endl;
        }
    }
}