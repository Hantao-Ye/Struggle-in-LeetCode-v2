#include <string>

class Solution
{
public:
    bool isPalindrome(std::string s)
    {
        for (int left = 0, right = s.size() - 1; left < right; left++, right--)
        {
            while (left < right && !isalnum(s[left]))
            {
                left++;
            }
            while (left < right && !isalnum(s[right]))
            {
                right--;
            }

            if (tolower(s[left]) != tolower(s[right]))
            {
                return false;
            }
        }

        return true;
    }
};