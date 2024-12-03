#include <iostream>
#include <vector>

class Solution
{
public:
    std::string addSpaces(std::string s, std::vector<int> &spaces)
    {
        size_t s_idx(0), spaces_idx(0);
        std::string output{};

        while (s_idx < s.size())
        {
            if (spaces_idx < spaces.size() && s_idx == spaces[spaces_idx])
            {
                output.push_back(' ');
                spaces_idx++;
            }

            output.push_back(s[s_idx++]);
        }

        return output;
    }
};

int main()
{
    Solution sol{};

    while (true)
    {
        std::string s;
        std::vector<int> spaces{};

        std::getline(std::cin, s);

        if (s.size() == 0)
            break;

        int val(0);
        while (std::cin >> val)
        {
            spaces.push_back(val);
        }

        std::cout << sol.addSpaces(s, spaces) << std::endl;
    }

    return 0;
}