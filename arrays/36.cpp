#include <vector>
#include <unordered_set>

bool isValidSudoku(std::vector<std::vector<char>> &board)
{
    for (int i = 0; i < 9; i++)
    {
        std::unordered_set<int> set{};

        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] != '.')
            {
                int digit = board[i][j] - '0';
                if (set.find(digit) == set.end())
                {
                    set.insert(digit);
                }
                else
                {
                    return false;
                }
            }
        }

        set.clear();
    }

    for (int j = 0; j < 9; j++)
    {
        std::unordered_set<int> set{};

        for (int i = 0; i < 9; i++)
        {
            if (board[i][j] != '.')
            {
                int digit = board[i][j] - '0';
                if (set.find(digit) == set.end())
                {
                    set.insert(digit);
                }
                else
                {
                    return false;
                }
            }
        }
        set.clear();
    }

    for (int i = 0; i < 9; i++)
    {
        std::unordered_set<int> set{};

        for (int j = 0; j < 9; j++)
        {
            int row = 3 * (i / 3) + j / 3;
            int column = 3 * (i % 3) + j % 3;

            if (board[row][column] != '.')
            {
                int digit = board[row][column] - '0';
                if (set.find(digit) == set.end())
                {
                    set.insert(digit);
                }
                else
                {
                    return false;
                }
            }
        }
        set.clear();
    }

    return true;
}