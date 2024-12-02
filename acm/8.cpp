#include <iostream>
#include <vector>

class Solution
{
public:
    int minimum_operations(std::vector<int> bricks, int sum)
    {
        int operations = 0;
        int avg = sum / bricks.size();

        for (const auto &brick : bricks)
        {
            if (brick > avg)
            {
                operations += brick - avg;
            }
        }

        return operations;
    }
};

int main()
{
    Solution s{};

    int n(0);
    while (std::cin >> n)
    {
        if (n == 0)
        {
            break;
        }

        int sum = 0;
        std::vector<int> bricks(n, 0);

        for (int i = 0; i < n; i++)
        {
            std::cin >> bricks[i];
            sum += bricks[i];
        }

        std::cout << s.minimum_operations(bricks, sum) << std::endl
                  << std::endl;
    }

    return 0;
}