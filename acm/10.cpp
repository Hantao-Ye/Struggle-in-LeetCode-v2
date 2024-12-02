#include <iostream>

class Solution
{
public:
    int maximum_day(int charge, int bonus)
    {

        int days = charge + charge / bonus;
        int count = charge / bonus + charge % bonus;
        while (count / bonus != 0)
        {
            days += count / bonus;
            count = count / bonus + count % bonus;
        }

        return days;
    }
};

int main()
{
    int k(0), m(0);
    Solution s{};
    while (std::cin >> k >> m)
    {
        if (k == m && k == 0)
        {
            break;
        }

        std::cout << s.maximum_day(k, m) << std::endl;
    }
}