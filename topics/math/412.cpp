#include <string>
#include <vector>
#include <iostream>
#include <sstream>

class Solution
{
public:
    std::vector<std::string> fizzBuzz(int n)
    {
        std::vector<std::string> output(n);

        for (int i = 0; i < n; i++)
        {
            int val = i + 1;
            std::string str{};

            if (val % 3 == 0 && val % 5 == 0)
            {
                str = "FizzBuzz";
            }
            else if (val % 3 == 0)
            {
                str = "Fizz";
            }
            else if (val % 5 == 0)
            {
                str = "Buzz";
            }
            else
            {
                str = std::to_string(val);
            }

            output[i] = str;
        }

        return output;
    }
};

int main()
{
    Solution s{};
    while (true)
    {
        std::string str{};
        std::getline(std::cin, str);
        if (str.size() == 0)
            break;

        int val(0);
        std::istringstream iss(str);
        while (iss >> val)
        {
            auto output = s.fizzBuzz(val);

            for (int i = 0; i < val; i++)
            {
                std::cout << output[i] << " ";
            }

            std::cout << std::endl;
        }
    }

    return 0;
}