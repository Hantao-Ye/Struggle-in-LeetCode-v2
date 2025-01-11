#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

class Solution
{
public:
    std::vector<std::string> wordSubsets(std::vector<std::string> &words1, std::vector<std::string> &words2)
    {
        std::unordered_map<char, int> global_map;

        for (const std::string &word : words2)
        {
            std::unordered_map<char, int> local_map;

            for (const char c : word)
            {
                if (local_map.find(c) == local_map.end())
                {
                    local_map[c] = 1;
                }
                else
                {
                    local_map[c]++;
                }

                if (global_map.find(c) == global_map.end() || global_map[c] < local_map[c])
                {
                    global_map[c] = local_map[c];
                }
            }
        }

        std::vector<std::string> output;

        for (const std::string &word : words1)
        {
            std::unordered_map<int, char> local_map;

            for (const char c : word)
            {
                if (local_map.find(c) == local_map.end())
                {
                    local_map[c] = 1;
                }
                else
                {
                    local_map[c]++;
                }
            }

            bool valid = true;
            for (auto it = global_map.begin(); it != global_map.end(); it++)
            {
                if (local_map.find(it->first) == local_map.end() || local_map[it->first] < it->second)
                {
                    valid = false;
                    break;
                }
            }

            if (valid)
            {
                output.push_back(word);
            }
        }

        return output;
    }
};

int main()
{
}
