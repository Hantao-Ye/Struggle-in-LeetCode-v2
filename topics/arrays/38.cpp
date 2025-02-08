#include <iostream>
#include <string>

class Solution
{
public:
    std::string countAndSay(int n)
    {
        std::string output = "1";

        while (--n > 0)
        {
            std::string temp = "";
            int prev = output.front() - '0', count = 1;
            for (int i = 1; i < output.size(); i++)
            {
                if (output[i] - '0' != prev)
                {
                    temp.push_back('0' + count);
                    temp.push_back('0' + prev);

                    prev = output[i] - '0';
                    count = 1;
                }
                else
                {
                    count++;
                }
            }

            temp.push_back('0' + count);
            temp.push_back('0' + prev);

            output = temp;
        }

        return output;
    }
};

int main()
{
    Solution sol;
    std::string line;

    while (true)
    {
        std::getline(std::cin, line);
        if (line.size() == 0)
        {
            break;
        }

        int n = std::stoi(line);

        std::cout << sol.countAndSay(n) << std::endl;
    }

    return 0;
}