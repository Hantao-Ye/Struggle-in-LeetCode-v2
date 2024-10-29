#include <vector>

int reverse(int x)
{
    int sign = x >= 0 ? 1 : -1;

    if (x == (1 << 31))
        return 0;

    int convert_num = sign * x;
    std::vector<int> convert_array{};

    while (convert_num > 0)
    {
        convert_array.push_back(convert_num % 10);
        convert_num /= 10;
    }

    int result_num = 0;
    for (int i = 0; i < convert_array.size(); i++)
    {
        if ((result_num > 2147483647 / 10) ||
            (sign > 0 && result_num == 2147483647 / 10 && convert_array[i] > 7) ||
            (sign < 0 && result_num == 2147483647 / 10 && convert_array[i] > 8))
        {
            return 0;
        }

        result_num *= 10;
        result_num += convert_array[i];
    }

    return sign * result_num;
}