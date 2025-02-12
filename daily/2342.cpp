#include <vector>
#include <unordered_map>
#include <queue>

class Solution
{
public:
    int maximumSum(std::vector<int> &nums)
    {
        std::unordered_map<int, std::priority_queue<int, std::vector<int>>> map;
        int max_sum = -1;

        for (const int &num : nums)
        {
            int digit_sum = 0;
            int temp = num;
            while (temp > 0)
            {
                digit_sum += temp % 10;
                temp /= 10;
            }

            if (map.find(digit_sum) == map.end())
            {
                std::priority_queue<int, std::vector<int>> pq;
                pq.push(num);

                map[digit_sum] = pq;
            }
            else
            {
                map[digit_sum].push(num);
            }
        }

        int max_sum = -1;
        for (auto map_iter = map.begin(); map_iter != map.end(); map_iter++)
        {
            if (map_iter->second.size() > 1)
            {
                auto pq = map_iter->second;

                int first = pq.top();
                pq.pop();
                int second = pq.top();

                max_sum = std::max(max_sum, first + second);
            }
        }

        return max_sum;
        // if using 81 + 1 for storing maximum number with similar digit count, the time will be O(n)
    }
};