#include <vector>
#include <iostream>
#include <sstream>
#include <unordered_map>

class Solution
{
public:
    std::vector<std::string> letterCombinations(std::string digits)
    {
        output.clear();
        str.clear();

        if (digits.size() == 0)
        {
            return {};
        }

        backtracking(digits, 0);

        return output;
    }

private:
    std::vector<std::string> output;
    std::string str;
    std::unordered_map<int, std::string> map{
        {2, "abc"},
        {3, "def"},
        {4, "ghi"},
        {5, "jkl"},
        {6, "mno"},
        {7, "pqrs"},
        {8, "tuv"},
        {9, "wxyz"},
    };

    void backtracking(const std::string &s, size_t index)
    {
        if (index == s.size())
        {
            output.push_back(str);
        }

        int digit = s[index] - '0';
        for (const auto &c : map[digit])
        {
            str.push_back(c);
            backtracking(s, index + 1);
            str.pop_back();
        }

        return;
    }
};

int main()
{
    Solution s{};

    while (true)
    {
        std::string line{};
        std::getline(std::cin, line);

        auto result = s.letterCombinations(line);

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

    return 0;
}