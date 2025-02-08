#include <vector>
#include <iostream>
#include <sstream>
#include <string>

class Solution
{
public:
    bool exist(std::vector<std::vector<char>> &board, std::string word)
    {
        output = false;
        visited = std::vector<std::vector<bool>>(board.size(), std::vector<bool>(board[0].size(), false));

        std::vector<std::pair<int, int>> start_indices;

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == word.front())
                {
                    start_indices.push_back({i, j});
                }
            }
        }

        for (auto indices : start_indices)
        {
            visited[indices.first][indices.second] = true;
            backtracking(board, word, indices.first, indices.second, 1);
            visited[indices.first][indices.second] = false;

            if (output)
            {
                break;
            }
        }

        return output;
    }

private:
    void backtracking(std::vector<std::vector<char>> &board, std::string &word, int i, int j, int index)
    {
        if (index == word.size())
        {
            output = true;
            return;
        }

        int m = board.size(), n = board[0].size();

        if (i - 1 >= 0 && board[i - 1][j] == word[index] && !visited[i - 1][j])
        {
            visited[i - 1][j] = true;
            backtracking(board, word, i - 1, j, index + 1);
            visited[i - 1][j] = false;
        }

        if (i + 1 < m && board[i + 1][j] == word[index] && !visited[i + 1][j])
        {
            visited[i + 1][j] = true;
            backtracking(board, word, i + 1, j, index + 1);
            visited[i + 1][j] = false;
        }

        if (j - 1 >= 0 && board[i][j - 1] == word[index] && !visited[i][j - 1])
        {
            visited[i][j - 1] = true;
            backtracking(board, word, i, j - 1, index + 1);
            visited[i][j - 1] = false;
        }

        if (j + 1 < n && board[i][j + 1] == word[index] && !visited[i][j + 1])
        {
            visited[i][j + 1] = true;
            backtracking(board, word, i, j + 1, index + 1);
            visited[i][j + 1] = false;
        }
    }

    std::vector<std::vector<bool>> visited;
    bool output;
};

int main()
{
    std::string str;
    Solution s{};

    while (true)
    {
        std::getline(std::cin, str);

        if (str.size() == 0)
        {
            break;
        }

        std::string word = str;
        std::vector<std::vector<char>> board;
        while (true)
        {
            std::getline(std::cin, str);

            if (str.size() == 0)
            {
                break;
            }

            std::istringstream iss(str);

            char c;
            std::vector<char> row;

            while (iss >> c)
            {
                row.push_back(c);
            }
            board.push_back(row);
        }

        std::cout << s.exist(board, word) << std::endl;
    }

    return 0;
}
