#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> assignElements(vector<int> &groups, vector<int> &elements)
    {
        std::unordered_map<int, int> elements_map;
        std::vector<int> output(groups.size(), -1);

        for (int i = 0; i < elements.size(); i++)
        {
            int num = elements[i];

            if (elements_map.find(num) == elements_map.end() || elements_map[num] > i)
            {
                elements_map[num] = i;
            }
        }

        for (int i = 0; i < groups.size(); i++)
        {
            int num = groups[i];

            for (int d = 1; d * d <= num; d++)
            {
                if (num % d == 0)
                {
                    if (elements_map.find(d) != elements_map.end())
                    {
                        if (output[i] == -1 || elements_map[d] < output[i])
                        {
                            output[i] = elements_map[d];
                        }
                    }

                    if (d * d != num)
                    {
                        int larger_d = num / d;
                        if (elements_map.find(larger_d) != elements_map.end())
                        {
                            if (output[i] == -1 || elements_map[larger_d] < output[i])
                            {
                                output[i] = elements_map[larger_d];
                            }
                        }
                    }
                }
            }
        }

        return output;
    }
};

int main()
{
    Solution sol;
    std::vector<int> groups = {10, 21, 30, 41}, elements = {2, 1};

    sol.assignElements(groups, elements);
}