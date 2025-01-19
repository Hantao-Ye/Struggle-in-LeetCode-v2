#include <vector>

using namespace std;

class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        vector<int> output;

        int i = 0, j = 0;
        int m = grid.size(), n = grid[0].size();

        bool right = true, finished = false;

        while (i < m && j < n && !finished)
        {
            output.push_back(grid[i][j]);

            if (right)
            {
                if (j + 2 < n)
                {
                    j += 2;
                } else if (j + 1 < n && i + 1 < m)
                {
                    j += 1;
                    i += 1;

                    right = false;
                } else if (i + 1 < m && j - 1 >= 0)
                {
                    j -= 1;
                    i += 1;

                    right = false;
                } else {
                    finished = true;
                }
            } else {
                if (j - 2  >= 0)
                {
                    j -= 2;
                } else if (j - 1 >= 0 && i + 1 < m)
                {
                    j -= 1;
                    i += 1;

                    right = true;
                } else if (i + 1 < m && j + 1 < n)
                {
                    j += 1;
                    i += 1;

                    right = true;
                } else {
                    finished = true;
                }
            }

        }

        return output;    
    }
};
