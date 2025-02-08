#include <vector>
#include <queue>
#include <iostream>

class Solution
{
public:
    int numIslands(std::vector<std::vector<char>> &grid)
    {
        int count = 0;
        int m = grid.size(), n = grid[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    count++;
                    grid[i][j] = '0';

                    std::queue<std::pair<int, int>> queue;
                    queue.push({i, j});

                    while (!queue.empty())
                    {
                        auto indices = queue.front();
                        queue.pop();

                        int r = indices.first, c = indices.second;
                        if (r - 1 >= 0 && grid[r - 1][c] == '1')
                        {
                            grid[r - 1][c] = '0';
                            queue.push({r - 1, c});
                        }

                        if (r + 1 < m && grid[r + 1][c] == '1')
                        {
                            grid[r + 1][c] = '0';
                            queue.push({r + 1, c});
                        }

                        if (c - 1 >= 0 && grid[r][c - 1] == '1')
                        {
                            grid[r][c - 1] = '0';
                            queue.push({r, c - 1});
                        }

                        if (c + 1 < n && grid[r][c + 1] == '1')
                        {
                            grid[r][c + 1] = '0';
                            queue.push({r, c + 1});
                        }
                    }
                }
            }
        }

        return count;
    }
};

int main()
{
}