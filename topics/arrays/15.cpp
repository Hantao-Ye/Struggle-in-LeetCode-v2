#include <algorithm>
#include <iostream>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <vector>

class Solution
{
public:
    std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
    {
        std::sort(nums.begin(), nums.end());

        std::vector<std::vector<int>> output{};

        for (size_t i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                break;
            }

            std::unordered_set<int> set{};
            if (i + 1 < nums.size())
            {
                set.insert(nums[i + 1]);
            }

            for (size_t j = i + 2; j < nums.size(); j++)
            {
                int sum = nums[i] + nums[j];

                if (set.find(-sum) != set.end())
                {
                    output.push_back({nums[i], -sum, nums[j]});

                    while (j + 1 < nums.size() && nums[j] == nums[j + 1])
                    {
                        j++;
                    }
                }

                set.insert(nums[j]);
            }

            while (i + 1 < nums.size() && nums[i] == nums[i + 1])
            {
                i++;
            }
        }

        return output;
    }
};

int main()
{
    Solution s{};

    while (true)
    {
        std::string str{};
        std::getline(std::cin, str);
        if (str.size() == 0)
        {
            break;
        }

        int val{};
        std::istringstream iss(str);
        std::vector<int> input{};

        while (iss >> val)
        {
            input.push_back(val);
        }

        auto output = s.threeSum(input);

        std::cout << '[';
        for (const auto &array : output)
        {
            std::cout << '[';
            for (const auto &num : array)
            {
                std::cout << num;

                if (&num == &array.back())
                {
                    std::cout << ']';
                }
                else
                {
                    std::cout << ", ";
                }
            }

            if (&array != &output.back())
            {
                std::cout << ", ";
            }
        }
        std::cout << ']' << std::endl;
    }
}
