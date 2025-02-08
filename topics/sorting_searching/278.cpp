
class Solution
{
public:
    bool isBadVersion(int version);
    int firstBadVersion(int n)
    {
        int low = 1, high = n;
        while (low < high)
        {
            int mid = low + (high - low) / 2;

            bool bad = isBadVersion(mid);
            if (bad)
            {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};