#include <vector>

class Solution
{
public:
    std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>> &image, int sr, int sc, int color)
    {
        visit(image, sr, sc, image[sr][sc], color);

        return image;
    }

    void visit(std::vector<std::vector<int>> &image, int i, int j, int old_color, int new_color)
    {
        if (image[i][j] != old_color || image[i][j] == new_color)
        {
            return;
        }

        image[i][j] = new_color;

        if (i > 0)
        {
            visit(image, i - 1, j, old_color, new_color);
        }
        if (i < image.size() - 1)
        {
            visit(image, i + 1, j, old_color, new_color);
        }

        if (j > 0)
        {
            visit(image, i, j - 1, old_color, new_color);
        }
        if (j < image[0].size() - 1)
        {
            visit(image, i, j + 1, old_color, new_color);
        }
    }
};