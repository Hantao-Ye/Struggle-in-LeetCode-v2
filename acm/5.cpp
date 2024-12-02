#include <iostream>
#include <sstream>
#include <vector>

int main()
{
    while (true)
    {
        std::string input{};
        std::getline(std::cin, input);

        if (input.size() > 0)
        {
            std::vector<int> arr;
            std::istringstream iss(input);
            int value(0);

            while (iss >> value)
            {
                arr.push_back(value);
            }

            std::cout << arr[0] + arr[1] << std::endl
                      << std::endl;
        }
        else
        {
            break;
        }
    }

    return 0;
}