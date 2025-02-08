#include <string>

bool isPalindrome(std::string s)
{
    std::string filtered_str{};

    for (auto it = s.begin(); it != s.end(); it++)
    {
        if (*it >= 'a' && *it <= 'z')
        {
            filtered_str.push_back(*it);
        }
        else if (*it >= 'A' && *it <= 'Z')
        {
            filtered_str.push_back(*it + 'a' - 'A');
        } else if (*it >= '0' && *it <= '9')
        {
            filtered_str.push_back(*it);
        }
    }

    int size = filtered_str.size();
    for (int idx = 0; idx < size / 2; idx++)
    {
        if (filtered_str[idx] != filtered_str[size - 1 - idx])
        {
            return false;
        }
    }

    return true;
}