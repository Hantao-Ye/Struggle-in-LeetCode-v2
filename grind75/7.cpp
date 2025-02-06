#include <unordered_map>
#include <string>

class Solution
{
public:
    bool isValidAnagram(std::string s, std::string t)
    {
        std::unordered_map<char, int> map;

        for (const char c : s)
        {
            map[c]++;
        }

        for (const char c : t)
        {
            if (map.find(c) == map.end())
            {
                return false;
            }

            map[c]--;

            if (map[c] == 0)
            {
                map.erase(c);
            }
        }

        return map.empty();
    }
};