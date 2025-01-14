#include <vector>
#include <queue>
#include <unordered_map>

class Solution
{
public:
    std::vector<int> topKFrequent(std::vector<int> &nums, int k)
    {
        std::unordered_map<int, int> map;
        for (auto num : nums)
        {
            if (map.find(num) == map.end())
            {
                map[num] = 1;
            }
            else
            {
                map[num]++;
            }
        }

        auto comp = [&map](int a, int b)
        {
            return map[a] < map[b];
        };

        std::priority_queue<int, std::vector<int>, decltype(comp)> heap(comp);

        for (auto p : map)
        {
            heap.push(p.first);

            if (heap.size() > k)
            {
                heap.pop();
            }
        }

        std::vector<int> output(k, 0);
        for (int i = k - 1; i >= 0; i--)
        {
            output[i] = heap.top();
            heap.pop();
        }

        return output;
    }
};
