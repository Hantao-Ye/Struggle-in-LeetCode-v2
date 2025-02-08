#include <iostream>
#include <vector>
#include <unordered_set>

bool containsDuplicate(std::vector<int> &nums)
{
    std::unordered_set<int> set{};

    for (auto it = nums.begin(); it != nums.end(); it++)
    {
        if (set.find(*it) == set.end())
        {
            set.insert(*it);
        }
        else
        {
            return true;
        }
    }

    return {};
}