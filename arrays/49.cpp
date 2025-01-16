#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>

class Solution
{
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &strs)
    {
        std::unordered_map<std::string, std::vector<std::string>> map;

        for (std::string const &str : strs)
        {
            std::string mark('0', 26);

            for (char c : str)
            {
                mark[c - 'a']++;
            }

            if (map.find(mark) == map.end())
            {
                map[mark] = {str};
            }
            else
            {
                map[mark].push_back(str);
            }
        }

        std::vector<std::vector<std::string>> output;
        for (auto it = map.begin(); it != map.end(); it++)
        {
            output.push_back(it->second);
        }

        return output;
    }
};