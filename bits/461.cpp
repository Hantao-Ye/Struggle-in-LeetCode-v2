class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        int count = 0;

        while (x > 0 && y > 0)
        {
            count += (x % 2) ^ (y % 2);
            x /= 2;
            y /= 2;
        }

        while (x > 0)
        {
            count += (x % 2);
            x /= 2;
        }

        while (y > 0)
        {
            count += (y % 2);
            y /= 2;
        }

        return count;
    }
};