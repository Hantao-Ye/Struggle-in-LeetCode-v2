#include <vector>
#include <string>

class Solution {
public:
    int smallestNumber(int n)
    {
        int count = 1;

        while (n > 0)
        {
            n /= 2;
            count *= 2;
        }

        return count - 1;
    }
};