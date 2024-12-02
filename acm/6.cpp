#include <iostream>

int main()
{
    int line_count(0);

    while (std::cin >> line_count)
    {
        while (line_count-- > 0)
        {
            int num_count(0);
            std::cin >> num_count;

            int output(0);
            while (num_count-- > 0)
            {
                int num(0);
                std::cin >> num;
                output += num;
            }

            std::cout << output << std::endl;
            if (line_count != 0)
            {
                std::cout << std::endl;
            }
        }
    }

    return 0;
}