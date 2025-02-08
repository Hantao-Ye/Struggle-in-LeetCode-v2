#include <iostream>
#include <sstream>
#include <vector>

class Solution
{
public:
    std::string longestCommonPrefix(std::vector<std::string> &strs)
    {
        std::string minimum_length_str = strs.front();

        for (const auto &str : strs)
        {
            if (str.size() < minimum_length_str.size())
            {
                minimum_length_str = str;
            }
        }

        for (const auto &str : strs)
        {
            if (minimum_length_str.size() == 0)
            {
                break;
            }

            for (int idx = minimum_length_str.size() - 1; idx >= 0; idx--)
            {
                if (str[idx] != minimum_length_str[idx])
                {
                    minimum_length_str = minimum_length_str.substr(0, idx);
                }
            }
        }

        return minimum_length_str;
    }
};
