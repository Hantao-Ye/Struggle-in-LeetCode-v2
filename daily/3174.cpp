#include <string>
#include <iostream>

class Solution
{
public:
    std::string clearDigits(std::string s)
    {
        std::string output;

        for (int i = 0; i < s.size(); i++)
        {
            if (isdigit(s[i]))
            {
                if (output.size() > 0)
                {
                    output.pop_back();
                }
            }
            else
            {
                output.push_back(s[i]);
            }
        }

        return output;
    }
};

int main()
{
    Solution sol;

    std::string str = "cb34";

    std::cout << sol.clearDigits(str) << std::endl;
}