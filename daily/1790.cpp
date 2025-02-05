#include <string>
#include <vector>

class Solution
{
public:
    bool areAlmostEqual(std::string s1, std::string s2)
    {
        if (s1.size() != s2.size())
        {
            return false;
        }

        std::vector<int> indices;
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] != s2[i])
            {
                indices.push_back(i);
            }

            if (indices.size() > 2)
            {
                return false;
            }
        }

        if (indices.size() == 0)
        {
            return true;
        }
        else if (indices.size() == 2)
        {
            if (s1[indices.front()] == s2[indices.back()] && s1[indices.back()] == s2[indices.front()])
            {
                return true;
            }
        }

        return false;
    }
};