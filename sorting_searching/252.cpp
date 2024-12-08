#include <vector>
#include <sstream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    bool canAttendMeetings(std::vector<std::vector<int>> &intervals)
    {
        std::sort(intervals.begin(), intervals.end());

        for (size_t i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] < intervals[i - 1][1])
            {
                return false;
            }
        }

        return true;
    }
};