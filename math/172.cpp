class Solution
{
public:
    int trailingZeroes(int n)
    {
        int five_count = 0;

        for (int i = 0; i <= n; i += 5)
        {
            int val = i;
            while (val % 5 == 0 && val != 0)
            {
                five_count++;
                val /= 5;
            }
        }

        return five_count;
    }
};