#include <string>

class Solution
{
public:
    std::string longestPalindrome(std::string s)
    {
        std::string output;

        for (int i = 0; i < s.size(); i++)
        {
            std::string odd = palindrome(s, i, i);
            output = odd.size() < output.size() ? output : odd;

            if (i > 0 && s[i] == s[i - 1])
            {
                std::string even = palindrome(s, i - 1, i);
                output = even.size() < output.size() ? output : even;
            }
        }

        return output;
    }

    std::string palindrome(std::string &s, int left, int right)
    {
        int size = s.size();

        while (left >= 0 && right <= size - 1 && s[left] == s[right])
        {
            left--;
            right++;
        }

        return s.substr(left + 1, right - left - 1);
    }
};