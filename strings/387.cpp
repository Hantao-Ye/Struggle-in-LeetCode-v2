#include <string>
#include <unordered_map>

int firstUniqChar(std::string s)
{
    std::unordered_map<char, int> map{};
    int size = s.size();

    for (auto it = s.begin(); it != s.end(); it++)
    {
        if (map.find(*it) == map.end())
        {
            map[*it] = it - s.begin();
        }
        else
        {
            map[*it] = size;
        }
    }

    int index = size;
    for (auto it = map.begin(); it != map.end(); it++)
    {
        if (it->second < index)
        {
            index = it->second;
        }
    }

    return index == size ? -1 : index;
}
