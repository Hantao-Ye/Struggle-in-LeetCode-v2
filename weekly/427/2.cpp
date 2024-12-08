#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution
{
public:
    int maxRectangleArea(vector<vector<int>> &points)
    {
        vector<vector<int>> grid(102, vector<int>(102, 0));

        int max_area = -1;

        for (const auto &point : points)
        {
            grid[point[0]][point[1]] = 1;
            grid[101][point[1]] = 1;
            grid[point[0]][101] = 1;
        }

        for (int i = 0; i <= 100; i++)
        {
            if (!grid[i][101])
            {
                continue;
            }

            for (int j = 0; j <= 100; j++)
            {
                if (!grid[101][j])
                {
                    continue;
                }

                if (grid[i][j])
                {
                    int i_ = -1, j_ = -1;
                    for (int another_i = i + 1; another_i <= 100; another_i++)
                    {
                        if (!grid[another_i][101])
                        {
                            continue;
                        }

                        if (grid[another_i][j])
                        {
                            i_ = another_i;
                            break;
                        }
                    }

                    for (int another_j = j + 1; another_j <= 100; another_j++)
                    {
                        if (!grid[101][another_j])
                        {
                            continue;
                        }

                        if (grid[i][another_j])
                        {
                            j_ = another_j;
                            break;
                        }
                    }

                    if (j_ == -1)
                    {
                        break;
                    }
                    else if (i_ == -1)
                    {
                        continue;
                    }
                    else if (grid[i_][j_])
                    {
                        bool contains = false;
                        for (int check_i = i; check_i <= i_; check_i++)
                        {
                            if (!grid[check_i][101])
                            {
                                continue;
                            }
                            for (int check_j = j; check_j <= j_; check_j++)
                            {

                                if (!grid[101][check_j] || (check_i == i && check_j == j) || (check_i == i_ && check_j == j) || (check_i == i && check_j == j_) || (check_i == i_ && check_j == j_))
                                {
                                    continue;
                                }

                                if (grid[check_i][check_j])
                                {
                                    contains = true;
                                    break;
                                }
                            }

                            if (contains)
                            {
                                break;
                            }
                        }

                        if (!contains)
                        {
                            max_area = max(max_area, (j_ - j) * (i_ - i));
                        }
                    }
                }
            }
        }

        return max_area;
    }
};

int main()
{
    Solution s{};

    std::vector<std::vector<int>> nums = {{1, 1}, {1, 3}, {3, 1}, {3, 3}};
    std::cout << s.maxRectangleArea(nums) << std::endl;
}