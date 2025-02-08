#include <vector>
#include <unordered_map>

std::vector<int> intersect(std::vector<int> &nums1, std::vector<int> &nums2)
{
    std::vector<int> result{};
    std::unordered_map<int, int> map{};

    for (auto it = nums1.begin(); it != nums1.end(); it++)
    {
        if (map.find(*it) == map.end())
        {
            map.insert(std::pair<int, int> (*it, 1));
        } else {
            map[*it]++;
        }
    }

    for (auto it = nums2.begin(); it != nums2.end(); it++)
    {
        if (map.find(*it) != map.end())
        {
            result.push_back(*it);
            if (--map[*it] == 0) {
                map.erase(*it);
            }
        }
    }

    return result;
}