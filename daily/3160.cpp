#include <vector>
#include <unordered_map>

class Solution
{
public:
    std::vector<int> queryResults(int limit, std::vector<std::vector<int>> &queries)
    {
        std::unordered_map<int, int> colors;
        std::vector<int> output;
        std::unordered_map<int, int> color_count;

        for (const auto &query : queries)
        {
            int index = query.front(), color = query.back();

            if (colors.find(index) == colors.end())
            {
                colors[index] = color;
                color_count[color]++;
            } else if (colors[index] != color)
            {
                color_count[colors[index]]--;

                if (color_count[colors[index]] == 0)
                {
                    color_count.erase(colors[index]);
                }

                colors[index] = color;
                color_count[color]++;
            }

            output.push_back(color_count.size());
        }

        return output;
    }
};