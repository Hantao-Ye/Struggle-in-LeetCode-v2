#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums)
    {
        int count = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = std::max(0, i - nums[i]); j <= i; j++)
            {
                count += nums[j];
            }
        }

        return count;
    }
};

int main()
{
    Solution sol;
    std::vector<int> input {3, 1, 1, 2};

    std:cout << sol.subarraySum(input) << std::endl;
}