#include <vector>
#include <deque>
#include <climits>
#include <array>

class Solution
{
public:
    std::vector<std::vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int minimumObstacles(std::vector<std::vector<int>> &grid)
    {
        int m = grid.size(), n = grid[grid.size() - 1].size();

        std::vector<std::vector<int>> num_obstacles(m, std::vector<int>(n, INT_MAX));
        std::deque<std::array<int, 3>> deque{};

        deque.push_back({0, 0, 0});
        num_obstacles[0][0] = 0;

        while (!deque.empty())
        {
            auto grid_point = deque.front();
            deque.pop_front();

            int obstacles = grid_point[0], row = grid_point[1], col = grid_point[2];

            for (auto d : directions)
            {
                int new_row = row + d[0], new_col = col + d[1];

                if (new_row >= 0 && new_row < m && new_col >= 0 && new_col < n && num_obstacles[new_row][new_col] == INT_MAX)
                {
                    if (grid[new_row][new_col] == 1)
                    {
                        num_obstacles[new_row][new_col] = obstacles + 1;
                        deque.push_back({obstacles + 1, new_row, new_col});
                    }
                    else
                    {
                        num_obstacles[new_row][new_col] = obstacles;
                        deque.push_front({obstacles, new_row, new_col});
                    }
                }
            }
        }

        return num_obstacles[m - 1][n - 1];
    }
};