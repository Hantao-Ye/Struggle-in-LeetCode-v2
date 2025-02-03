#include <string>
#include <stack>
#include <unordered_map>

class Solution
{
    bool isValid(std::string s)
    {
        std::stack<char> brackets;

        static const std::unordered_map<char, char> bracketPairs = {
            {')', '('},
            {'}', '{'},
            {']', '['},
        };

        for (const char c : s)
        {
            if (c == '(' || c == '[' || c == '{')
            {
                brackets.push(c);
                continue;
            }

            if (auto it = bracketPairs.find(c); it != bracketPairs.end())
            {
                if (brackets.empty() || brackets.top() != it->second)
                {
                    return false;
                }

                brackets.pop();
            }
        }

        return brackets.empty();
    }
};