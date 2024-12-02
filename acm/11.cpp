#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

class Solution
{
public:
    int hierarchy(std::vector<std::vector<int>> &input, int self, int target)
    {
        int self_height = 0, target_height = 0;

        std::unordered_map<int, int> map{};
        std::unordered_set<int> set{};
        int ancestor = -1;

        for (const auto &line : input)
        {
            map.insert(std::pair<int, int>{line[0], line[1]});
            if (set.find(line[1]) == set.end())
            {
                set.insert(line[1]);
            }
            else
            {
                ancestor = line[1];
            }
        }

        while (target != ancestor)
        {
            target = map[target];
            target_height++;
        }

        while (self != ancestor)
        {
            self = map[self];
            self_height++;
        }

        return self_height - target_height;
    }
};

int main()
{
    int n(0);
    Solution s{};

    while (std::cin >> n)
    {
        std::vector<std::vector<int>> input{};
        while (n-- > 0)
        {
            std::vector<int> input_line{0, 0};

            std::cin >> input_line[0] >> input_line[1];
            input.push_back(input_line);
        }

        int result = s.hierarchy(input, 1, 2);
        if (result < 0)
        {
            std::cout << "You are my younger" << std::endl;
        }
        else if (result > 0)
        {
            std::cout << "You are my elder" << std::endl;
        }
        else
        {
            std::cout << "You are my brother" << std::endl;
        }
    }

    return 0;
}