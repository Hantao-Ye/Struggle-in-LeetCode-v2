#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_set>

class Solution
{
public:
    int countPrimes(int n)
    {
        if (n <= 2)
            return 0;

        std::vector<bool> numbers(n, true);
        numbers[1] = false;

        for (int i = 2; i < n; i++)
        {
            if (numbers[i])
            {
                for (int j = 2 * i; j < n; j += i)
                {
                    numbers[j] = false;
                }
            }
        }

        int primes_count = 0;
        for (int i = 1; i < n; i++)
        {
            primes_count += numbers[i];
        }

        return primes_count;
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

        int val;
        std::istringstream iss(str);
        while (iss >> val)
        {
            std::cout << s.countPrimes(val) << std::endl;
        }
    }

    return 0;
}