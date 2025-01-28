#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    int findMaxFish(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        int count = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int current_count = 0;
                if (grid[i][j] != 0)
                {
                    queue<pair<int, int>> q;

                    q.push({i, j});
                    current_count += grid[i][j];
                    grid[i][j] = 0;

                    while (!q.empty())
                    {
                        auto node = q.front();
                        q.pop();

                        if (node.first - 1 >= 0 && grid[node.first - 1][node.second] != 0)
                        {
                            current_count += grid[node.first - 1][node.second];
                            grid[node.first - 1][node.second] = 0;

                            q.push({node.first - 1, node.second});
                        }

                        if (node.first + 1 < m && grid[node.first + 1][node.second] != 0)
                        {
                            current_count += grid[node.first + 1][node.second];
                            grid[node.first + 1][node.second] = 0;

                            q.push({node.first + 1, node.second});
                        }

                        if (node.second - 1 >= 0 && grid[node.first][node.second - 1] != 0)
                        {
                            current_count += grid[node.first][node.second - 1];
                            grid[node.first][node.second - 1] = 0;

                            q.push({node.first, node.second - 1});
                        }

                        if (node.second + 1 < n && grid[node.first][node.second + 1] != 0)
                        {
                            current_count += grid[node.first][node.second + 1];
                            grid[node.first][node.second + 1] = 0;

                            q.push({node.first, node.second + 1});
                        }
                    }
                }

                count = max(count, current_count);
            }
        }

        return count;
    }
};