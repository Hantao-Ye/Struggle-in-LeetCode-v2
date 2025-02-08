#include <vector>

class Solution
{
public:
    bool searchMatrix(std::vector<std::vector<int>> &matrix, int target)
    {
        int m = matrix.size(), n = matrix.front().size();

        int i = m - 1, j = 0;

        while (i >= 0 && i < m && j >= 0 && j < n)
        {
            if (matrix[i][j] > target)
            {
                i--;
            }
            else if (matrix[i][j] < target)
            {
                j++;
            }
            else
            {
                return true;
            }
        }

        return false;
    }
};