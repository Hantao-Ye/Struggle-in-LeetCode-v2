#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<vector<int>> sortMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();

        std::unordered_map<int, std::vector<int>> diagonals;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (diagonals.find(i - j) == diagonals.end())
                {
                    diagonals[i - j] = {grid[i][j]};
                }
                else
                {
                    diagonals[i - j].push_back(grid[i][j]);
                }
            }
        }

        for (auto it = diagonals.begin(); it != diagonals.end(); it++)
        {
            if (it->first >= 0)
            {
                sort(it->second.begin(), it->second.end());
            }
            else
            {
                sort(it->second.begin(), it->second.end(), std::greater<int>());
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                grid[i][j] = diagonals[i - j].back();
                diagonals[i - j].pop_back();
            }
        }

        return grid;
    }
};