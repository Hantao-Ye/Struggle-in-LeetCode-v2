#include <string>
#include <unordered_map>

class Solution
{
public:
    bool canConstruct(std::string ransomNote, std::string magazine)
    {
        std::unordered_map<char, int> magazine_map;

        for (const char& c : magazine)
        {
            magazine_map[c]++;
        }

        for (const char & c: ransomNote)
        {
            if (magazine_map.find(c) == magazine_map.end())
            {
                return false;
            } else {
                magazine_map[c]--;

                if (magazine_map[c] == 0)
                {
                    magazine_map.erase(c);
                }
            }
        }

        return true;
    }
};