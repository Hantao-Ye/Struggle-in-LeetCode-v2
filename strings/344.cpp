#include <vector>

void reverseString(std::vector<char> &s)
{
    int size = s.size();

    for (int idx = 0; idx < size / 2; idx++)
    {
        char temp = s[idx];
        s[idx] = s[size - 1 - idx];
        s[size - 1 - idx] = temp;
    }
}