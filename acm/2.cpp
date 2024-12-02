#include <iostream>

int main()
{
    int n;
    while (std::cin >> n)
    {
        for (size_t i = 0; i < n; i++)
        {
            int a = 0, b = 0;
            std::cin >> a >> b;

            std::cout << a + b << std::endl;
        }
    }

    return 0;
}