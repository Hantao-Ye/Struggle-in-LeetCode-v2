#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> constructTransformedArray(vector<int> &nums)
    {
        std::vector<int> output{};
        int n = nums.size();

        for (size_t i = 0; i < n; i++)
        {
            output.push_back(nums[rotatedIndex(i, nums[i], n)]);
        }

        return output;
    }

    int rotatedIndex(int index, int step, int size)
    {
        if (index + step >= size)
        {
            return (index + step) % size;
        }
        else if (index + step < 0)
        {
            int sum = index + step;
            while (sum < 0)
            {
                sum += size;
            }
            return sum;
        }

        return index + step;
    }
};