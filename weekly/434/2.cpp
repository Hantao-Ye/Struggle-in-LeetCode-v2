#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>> &events)
    {
        vector<int> mentions(numberOfUsers, 0);
        int all_mentions = 0;

        auto message_time_comp = [](vector<string> &a, vector<string> &b)
        {
            if (stoi(a[1]) == stoi(b[1]))
            {
                if (a[0] == "OFFLINE")
                {
                    return true;
                } else if (b[1] == "OFFLINE")
                {
                    return false;
                }
            }

            return stoi(a[1]) < stoi(b[1]);
        };
        sort(events.begin(), events.end(), message_time_comp);

        unordered_set<int> online;
        for (int i = 0; i < numberOfUsers; i++)
        {
            online.insert(i);
        }
        queue<pair<int, int>> offline; // <id, time> pairs

        for (vector<string> const &event : events)
        {
            int timestamp = stoi(event[1]);
            while (!offline.empty() && timestamp >= offline.front().second)
            {
                online.insert(offline.front().first);
                offline.pop();
            }

            if (event[0] == "MESSAGE")
            {
                if (event[2] == "ALL")
                {
                    all_mentions++;
                }
                else if (event[2] == "HERE")
                {
                    for (auto it = online.begin(); it != online.end(); it++)
                    {
                        mentions[*it]++;
                    }
                }
                else
                {
                    istringstream iss(event[2]);
                    string id_str;
                    int id;
                    while (getline(iss, id_str, ' '))
                    {
                        id = stoi(id_str.substr(2));
                        mentions[id]++;
                    }
                }
            }
            else if (event[0] == "OFFLINE")
            {
                int timestamp = stoi(event[1]);
                int id = stoi(event[2]);

                online.erase(id);

                offline.push(pair<int, int>{id, timestamp + 60});
            }
        }

        for (int i = 0; i < numberOfUsers; i++)
        {
            mentions[i] += all_mentions;
        }

        return mentions;
    }
};

int main()
{
    std::vector<string> event1 = {"MESSAGE","2","HERE"};
    std::vector<string> event2 = {"OFFLINE","2","1"};
    std::vector<string> event3 = {"OFFLINE","1","0"};
    std::vector<string> event4 = {"MESSAGE","61","HERE"};

    std::vector<vector<string>> events = {event1, event2, event3, event4};
    int numberOfUsers = 3;
    Solution sol;
    auto mentions = sol.countMentions(numberOfUsers, events);

    return 0;
}