#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;


class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> map;
        for (char const& c : s)
        {
            map[c]++;
        }

        int even = s.size(), odd = 0;

        for (auto it = map.begin(); it != map.end(); it++)
        {
            if (it->second % 2 == 1 && it->second > odd)
            {
                odd = it->second;
            }

            if (it->second % 2 == 0 && it->second < even)
            {
                even = it->second;
            }
        }

        return odd - even;
    }
};