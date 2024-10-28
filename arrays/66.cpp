#include <vector>

std::vector<int> plusOne(std::vector<int> &digits)
{
    bool increment = false;

    for (int i = digits.size() - 1; i >= 0; i--)
    {
        int result = digits[i] + (int)(increment);
        if (i == digits.size() - 1)
        {
            result += 1;
        }

        if (result > 9)
        {
            increment = true;
            digits[i] = result - 10;
        }
        else
        {
            digits[i] = result;
            increment = false;
        }
    }

    if (increment)
    {
        digits.insert(digits.begin(), 1);
    }

    return digits;
}