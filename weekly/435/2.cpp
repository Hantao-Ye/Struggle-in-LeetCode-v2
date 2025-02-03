#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int maxDistance(string s, int k)
    {
        int step = 0;
        unordered_map<char, int> map;

        for (char const &c : s)
        {
            map[c]++;

            int current_step = 0;

            int n_count = map['N'];
            int s_count = map['S'];
            int w_count = map['W'];
            int e_count = map['E'];

            int vertical_min = min(n_count, s_count);
            int horizontal_min = min(w_count, e_count);

            current_step = abs(n_count - s_count) + abs(w_count - e_count);
            if (k >= vertical_min + horizontal_min)
            {
                current_step += 2 * (vertical_min + horizontal_min);
            } else {
                current_step += 2 * k;
            }

            if (current_step > step)
            {
                step = current_step;
            }
        }

        return step;
    }
};

int main()
{
    Solution sol;
    string s = "NWSE";
    int k = 1;

    std::cout << sol.maxDistance(s, k) << std::endl;
}