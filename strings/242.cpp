#include <string>
#include <unordered_map>

bool isAnagram(std::string s, std::string t)
{
    std::unordered_map<char, int> map;

    for (auto it = s.begin(); it != s.end(); it++)
    {
        if (map.find(*it) == map.end())
        {
            map[*it] = 1;
        }
        else
        {
            map[*it]++;
        }
    }

    for (auto it = t.begin(); it != t.end(); it++)
    {
        if (map.find(*it) == map.end())
        {
            return false;
        }
        else
        {
            if (map[*it] > 1)
            {
                map[*it]--;
            }
            else
            {
                map.erase(*it);
            }
        }
    }

    if (!map.empty())
    {
        return false;
    }

    return true;
}
