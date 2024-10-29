#include <string>

int myAtoi(std::string s)
{
    int start_idx = -1;
    int sign = 0;

    for (auto it = s.begin(); it != s.end(); it++)
    {
        if (*it == '+' || *it == '-' || (*it >= '0' && *it <= '9'))
        {
            if (*it == '+')
            {
                sign = 1;
            }
            else if (*it == '-')
            {
                sign = -1;
            }

            start_idx = it - s.begin();
            break;
        }
        else if (*it != ' ')
        {
            return 0;
        }
    }

    if (start_idx == -1)
    {
        return 0;
    }

    int result = 0;

    if (sign != 0)
    {
        start_idx++;
    }
    else
    {
        sign = 1;
    }

    for (auto it = s.begin() + start_idx; it != s.end(); it++)
    {
        if (*it < '0' || *it > '9')
        {
            break;
        }

        if (result > (-((1 << 31) + 1)) / 10)
        {
            if (sign > 0)
            {
                return (-((1 << 31) + 1));
            }
            else
            {
                return (1 << 31);
            }
        }
        else if (result == (-((1 << 31) + 1)) / 10)
        {
            if (sign > 0 && *it >= '7')
            {
                return (-((1 << 31) + 1));
            }
            else if (sign < 0 && *it >= '8')
            {
                return (1 << 31);
            }
        }

        result *= 10;
        result += (*it - '0');
    }

    return sign * result;
}