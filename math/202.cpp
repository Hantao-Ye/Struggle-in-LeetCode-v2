#include <unordered_set>

using namespace std;

class Solution
{
public:
    bool isHappy(int n)
    {
        int next;
        unordered_set<int> visited;

        while (n != 1)
        {
            next = 0;
            while (n > 0)
            {
                next += (n % 10) * (n % 10);
                n /= 10;
            }

            if (visited.find(next) != visited.end())
            {
                return false;
            }
            else
            {
                visited.insert(next);
            }

            n = next;
        }

        return true;
    }
};