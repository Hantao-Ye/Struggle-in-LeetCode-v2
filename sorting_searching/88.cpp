#include <vector>

class Solution
{
public:
    void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n)
    {
        int index_1 = m - 1, index_2 = n - 1;

        for (int index = m + n - 1; index >= 0; index--)
        {
            if (index_2 < 0)
            {
                return;
            }

            if (index_1 >= 0 && nums1[index_1] > nums2[index_2])
            {
                nums1[index] = nums1[index_1--];
            }
            else
            {
                nums1[index] = nums2[index_2--];
            }
        }
    }
};