#include <algorithm>
#include <queue>
#include <vector>

class Solution
{
public:
    int minMeetingRooms(std::vector<std::vector<int>> &intervals)
    {
        auto comp_front = [](std::vector<int> &a, std::vector<int> &b)
        {
            return a.front() < b.front();
        };
        auto comp_back = [](std::vector<int> &a, std::vector<int> &b)
        {
            return a.back() > b.back();
        };

        std::sort(intervals.begin(), intervals.end(), comp_front);

        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, decltype(comp_back)> queue(comp_back);

        size_t size = 0;

        for (std::vector<int> const &interval : intervals)
        {
            while (!queue.empty() && queue.top().back() <= interval.front())
            {
                queue.pop();
            }

            queue.push(interval);

            size = std::max(size, queue.size());
        }

        return (int)size;
    }
};