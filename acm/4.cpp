#include <iostream>

int main()
{
    int n(0);

    while (std::cin >> n)
    {
        if (n == 0)
            break;

        int result = 0;
        while (n-- > 0)
        {
            int num(0);
            std::cin >> num;

            result += num;
        }

        std::cout << result << std::endl;
    }

    return 0;
}