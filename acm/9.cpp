#include <iostream>

class Solution
{
public:
    int sum_of_odd_digits(std::string &str)
    {
        int result = 0;
        for (auto character : str)
        {
            int digit = (character - '0');

            if (digit % 2 == 0)
            {
                result += digit;
            }
        }

        return result;
    }
};

int main()
{
    Solution s{};
    while (true)
    {
        std::string str{};
        std::getline(std::cin, str);

        if (str.size() > 0)
        {
            std::cout << s.sum_of_odd_digits(str) << std::endl
                      << std::endl;
        }
        else
        {
            break;
        }
    }

    return 0;
}