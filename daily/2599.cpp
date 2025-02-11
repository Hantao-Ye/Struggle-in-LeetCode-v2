#include <vector>
#include <queue>

class Solution
{
public:
    int makePrefSumNonNegative(std::vector<int> &nums)
    {
        int count = 0;
        long long prefix_sum = 0;

        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

        for (const int &num : nums)
        {
            if (num < 0)
            {
                pq.push(num);
            }

            prefix_sum += num;

            if (prefix_sum < 0)
            {
                prefix_sum += -pq.top();
                pq.pop();

                count++;
            }
        }

        return count;
    }
};