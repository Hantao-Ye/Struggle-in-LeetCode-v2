#include <iostream>
#include <sstream>
#include <vector>
#include <numeric>

int main()
{
    while (true)
    {
        std::string input{};

        std::getline(std::cin, input);

        if (input.size() == 0)
        {
            break;
        }
        else
        {
            std::vector<int> arr{};
            int value{};
            std::istringstream iss(input);

            while (iss >> value)
            {
                arr.push_back(value);
            }

            std::cout << std::reduce(arr.begin(), arr.end()) << std::endl;
        }
    }

    return 0;
}