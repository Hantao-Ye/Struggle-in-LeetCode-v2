#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        unordered_map<char, int> map;

        for (const char &task : tasks)
        {
            map[task]++;
        }

        auto comp = [](pair<char, int> a, pair<char, int> b)
        {
            return a.second < b.second;
        };

        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(comp)> tasks_queue(comp);
        for (auto it = map.begin(); it != map.end(); it++)
        {
            tasks_queue.push(pair<int, int>{it->first, it->second});
        }

        queue<pair<char, pair<int, int>>> gap_queue; // task, working time, remaining count

        int task_count = 0;
        int time = 0;

        while (task_count < tasks.size())
        {
            while (!gap_queue.empty() && gap_queue.front().second.first < time)
            {
                tasks_queue.push(pair<char, int>(gap_queue.front().first, gap_queue.front().second.second));
                gap_queue.pop();
            }

            if (!tasks_queue.empty())
            {
                auto task = tasks_queue.top();
                tasks_queue.pop();


                if (task.second > 1)
                {
                    gap_queue.push({task.first, {time + n, task.second - 1}});
                }

                task_count++;
            }

            time++;
        }

        return time;
    }
};