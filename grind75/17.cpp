#include <string>
#include <unordered_map>

class Solution
{
public:
    int longestPalindrome(std::string s)
    {
        std::unordered_map<char, int> character_map;

        for (const char &c : s)
        {
            character_map[c]++;
        }

        int length = 0;
        for (auto it = character_map.begin(); it != character_map.end(); it++)
        {
            if (it->second % 2 == 0)
            {
                length += it->second;
            }
            else
            {
                if (length % 2 != 0)
                {
                    length += it->second - 1;
                }
                else
                {
                    length += it->second;
                }
            }
        }

        return length;
        // check the number of single character could reduce O(2 * n) to O(n)
    }
};