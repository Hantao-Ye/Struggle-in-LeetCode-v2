class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        if (n <= 0)
            return false;

        while (n > 1)
        {
            if (n % 3 != 0)
            {
                return false;
            }

            n /= 3;
        }

        return true;
        // without loop, find the maximum 3^k within 1 << 31 - 1, 
        // return n > 0 && 3^k % n;
    }
};