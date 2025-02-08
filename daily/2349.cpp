#include <queue>
#include <unordered_map>
#include <vector>

class NumberContainers
{
public:
    NumberContainers()
    {
        map_index_num.clear();
        map_num_index.clear();
    }

    void change(int index, int number)
    {
        if (map_index_num.find(index) == map_index_num.end())
        {
            map_index_num[index] = number;

            if (map_num_index.find(number) == map_num_index.end())
            {
                std::priority_queue<int, std::vector<int>, std::greater<int>> queue;
                queue.push(index);

                map_num_index[number] = queue;
            }
            else
            {
                while (!map_num_index[number].empty() && map_index_num[map_num_index[number].top()] != number)
                {
                    map_num_index[number].pop();
                }

                map_num_index[number].push(index);
            }
        }
        else
        {
            int old_number = map_index_num[index];
            map_index_num[index] = number;

            while (!map_num_index[old_number].empty() && map_index_num[map_num_index[old_number].top()] != old_number)
            {
                map_num_index[old_number].pop();
            }

            if (map_num_index[old_number].empty())
            {
                map_num_index.erase(old_number);
            }

            if (map_num_index.find(number) == map_num_index.end())
            {
                std::priority_queue<int, std::vector<int>, std::greater<int>> queue;
                queue.push(index);

                map_num_index[number] = queue;
            }
            else
            {
                while (!map_num_index[number].empty() && map_index_num[map_num_index[number].top()] != number)
                {
                    map_num_index[number].pop();
                }

                map_num_index[number].push(index);
            }
        }
    }

    int find(int number)
    {
        if (map_num_index.find(number) == map_num_index.end())
        {
            return -1;
        }

        return map_num_index[number].top();
    }

private:
    std::unordered_map<int, int> map_index_num;
    std::unordered_map<int, std::priority_queue<int, std::vector<int>, std::greater<int>>> map_num_index;
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */