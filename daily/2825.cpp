#include <iostream>
#include <sstream>

class Solution
{
public:
    bool canMakeSubsequence(std::string str1, std::string str2)
    {
        int idx_1 = 0, idx_2 = 0;
        if (str1.size() < str2.size())
            return false;

        for (; idx_1 < str1.size(); idx_1++)
        {
            if (isWithinIncrement(str1[idx_1], str2[idx_2]))
            {
                idx_2++;
            }
        }

        if (idx_2 == str2.size())
        {
            return true;
        }

        return false;
    }

private:
    bool isWithinIncrement(char a, char b)
    {
        return (((b - a) <= 1 && (b - a) >= 0) || (a - b) == 25);
    }
};

int main()
{
    Solution s{};
    std::string str1{}, str2{};

    while (true)
    {
        std::getline(std::cin, str1);
        if (str1.size() == 0)
        {
            break;
        }

        std::getline(std::cin, str2);

        std::cout << s.canMakeSubsequence(str1, str2) << std::endl;
    }

    return 0;
}