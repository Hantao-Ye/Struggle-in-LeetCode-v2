#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<int> searchRange(std::vector<int> &nums, int target)
    {
        std::vector<int> range{-1, -1};

        range[0] = findOccurrence(nums, target, true);
        range[1] = findOccurrence(nums, target, false);

        return range;
    }

    int findOccurrence(std::vector<int> &nums, int target, bool first)
    {
        int low = 0, high = nums.size() - 1, mid;

        while (low <= high)
        {
            mid = low + (high - low) / 2;

            if (nums[mid] < target)
            {
                low = mid + 1;
            }
            else if (nums[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                if (first)
                {
                    if (mid == low || nums[mid - 1] != target)
                    {
                        return mid;
                    }

                    high = mid - 1;
                }
                else
                {
                    if (mid == high || nums[mid + 1] != target)
                    {
                        return mid;
                    }

                    low = mid + 1;
                }
            }
        }

        return -1;
    }
};

int main()
{
    std::vector<int> input{5, 7, 7, 8, 8, 10};
    int target = 10;

    Solution sol;
    std::vector<int> output = sol.searchRange(input, target);

    std::cout << '[';
    for (int const &val : output)
    {
        std::cout << val;
        if (&val != &output.back())
        {
            std::cout << ',';
        }
    }
    std::cout << ']' << std::endl;

    return 0;
}
