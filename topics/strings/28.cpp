#include <vector>
#include <iostream>
#include <sstream>

class Solution
{
public:
    int strStr(std::string haystack, std::string needle)
    {
        auto next = generateNext(needle);

        int j = -1;
        for (int i = 0; i < haystack.size(); i++)
        {
            while (j >= 0 && haystack[i] != needle[j + 1])
            {
                j = next[j];
            }

            if (haystack[i] == needle[j + 1])
            {
                j++;
            }

            if (j == (needle.size() - 1))
            {
                return (i - needle.size() + 1);
            }
        }

        return -1;
    }

private:
    std::vector<int> generateNext(std::string &str)
    {
        int n = str.size();
        std::vector<int> next(n, -1);
        int j = -1;

        for (int i = 1; i < n; i++)
        {
            while (j >= 0 && str[i] != str[j + 1])
            {
                j = next[j];
            }

            if (str[i] == str[j + 1])
            {
                j++;
            }

            next[i] = j;
        }

        return next;
    }
};

int main()
{
    Solution sol{};

    while (true)
    {
        std::string haystack{}, needle{};
        std::getline(std::cin, haystack);
        std::getline(std::cin, needle);

        if (haystack.size() == 0 || needle.size() == 0)
        {
            break;
        }

        std::cout << sol.strStr(haystack, needle) << std::endl;
    }

    return 0;
}