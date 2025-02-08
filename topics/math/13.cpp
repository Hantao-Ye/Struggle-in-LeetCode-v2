#include <iostream>
#include <unordered_map>

class Solution
{
public:
    int romanToInt(std::string s)
    {
        int sum = 0;
        int prev = -1;
        for (const auto &c : s)
        {
            if (prev > 0 && map[c] > prev)
            {
                sum -= 2 * prev;
            }

            sum += map[c];
            prev = map[c];
        }

        return sum;
    }

private:
    std::unordered_map<char, int> map{
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}};
};

int main()
{
    Solution s{};
    while (true)
    {
        std::string str{};
        std::getline(std::cin, str);

        if (str.size() < 1)
        {
            break;
        }

        std::cout << s.romanToInt(str) << std::endl;
    }

    return 0;
}