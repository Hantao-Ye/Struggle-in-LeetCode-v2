#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Solution
{
public:
    int findPeakElement(std::vector<int> &nums)
    {
        int low = 0, high = nums.size() - 1;

        while (low < high)
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] < nums[mid + 1])
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }

        return low;
    }
};

int main()
{
    Solution sol;
    std::string line;

    while (true)
    {
        std::getline(std::cin, line);

        if (line.size() < 1)
        {
            break;
        }

        std::istringstream iss(line);

        int val;
        std::vector<int> input;

        while (iss >> val)
        {
            input.push_back(val);
        }

        std::cout << sol.findPeakElement(input) << std::endl;
    }

    return 0;
}