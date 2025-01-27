#include <string>

using namespace std;

class Solution
{
public:
    int titleToNumber(string columnTitle)
    {
        int val = 0;

        for (const char &c : columnTitle)
        {
            val *= 26;
            val += c - 'A' + 1;
        }

        return val;
    }
};