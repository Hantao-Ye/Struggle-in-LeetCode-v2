#include <string>
#include <deque>
#include <iostream>

class Solution
{
public:
    std::string removeOccurrences(std::string s, std::string part)
    {
        std::string output;
        std::deque<char> temp;

        for (int i = 0; i < s.size(); i++)
        {
            if (temp.size() < part.size())
            {
                temp.push_back(s[i]);
            }
            else
            {
                int j;
                for (j = 0; j < part.size(); j++)
                {
                    if (temp[j] != part[j])
                    {
                        break;
                    }
                }

                if (j == part.size())
                {
                    temp.clear();

                    while (output.size() > 0 && temp.size() < part.size() - 1)
                    {
                        temp.push_front(output.back());
                        output.pop_back();
                    }
                }
                else
                {
                    output.push_back(temp.front());
                    temp.pop_front();
                }

                temp.push_back(s[i]);
            }
        }

        int j;
        for (j = 0; j < part.size() && j < temp.size(); j++)
        {
            if (temp[j] != part[j])
            {
                break;
            }
        }

        if (j == part.size())
        {
            temp.clear();
        }

        while (!temp.empty())
        {
            output.push_back(temp.front());
            temp.pop_front();
        }

        return output;
    }
};

int main()
{
}