#include <string>
#include <unordered_map>

class Solution
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        std::unordered_map<char, int> map;

        size_t longest = 0;
        std::string current;
        int current_front_idx = 0;

        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if (map.find(c) == map.end() || map[c] == -1)
            {
                map[c] = i;
                current.push_back(c);
            }
            else
            {
                int k = map[c];
                map[c] = i;

                for (int j = current_front_idx; j < k; j++)
                {
                    map[s[j]] = -1;
                }

                current_front_idx = k + 1;
                current = s.substr(current_front_idx, i - k);
            }

            longest = std::max(longest, current.size());
        }

        return longest;
    }
};