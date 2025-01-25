#include <algorithm>
#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>> &intervals)
    {
        auto comp = [](std::vector<int> &a, std::vector<int> &b)
        {
            return a.front() < b.front();
        };

        std::sort(intervals.begin(), intervals.end(), comp);

        std::vector<std::vector<int>> output;
        output.push_back(intervals.front());

        for (int i = 1; i < intervals.size(); i++)
        {
            std::vector<int> interval = intervals[i];

            if (interval[0] <= output.back()[1])
            {
                output[output.size() - 1][1] = std::max(interval[1], output[output.size() - 1][1]);
            }
            else
            {
                output.push_back(interval);
            }
        }

        return output;
    }
};

int main()
{
    return 0;
}