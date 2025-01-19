#include <iostream>
#include <string>
#include <unordered_set>

class Solution
{
public:
    int countPalindromicSubsequence(std::string s)
    {
        int count = 0;
        std::unordered_set<char> letters;

        for (char c : s)
        {
            letters.insert(c);
        }

        for (char letter : letters)
        {
            int i = -1, j = 0;
            for (int k = 0; k < s.size(); k++)
            {
                if (s[k] == letter)
                {
                    if (i == -1)
                    {
                        i = k;
                    }

                    j = k;
                }
            }

            std::unordered_set<char> between;
            for (int k = i + 1; k < j; k++)
            {
                between.insert(s[k]);
            }

            count += between.size();
        }

        return count;
    }
};

int main()
{
    Solution s{};
    std::string input;

    while (true)
    {
        std::getline(std::cin, input);
        if (input.size() < 3)
        {
            break;
        }

        std::cout << s.countPalindromicSubsequence(input) << std::endl;
    }

    return 0;
}