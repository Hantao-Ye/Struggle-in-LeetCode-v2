#include <climits>

using namespace std;

class Solution
{
public:
    double myPow(double x, int n)
    {
        if (n == 0)
        {
            return 1;
        }
        else if (n < 0 && n != INT_MIN)
        {
            return myPow(1 / x, -n);
        }
        else if (n == 1)
        {
            return x;
        }
        else if (n % 2 != 0)
        {
            return x * myPow(x, n - 1);
        }

        return myPow(x * x, n / 2);
    }
};