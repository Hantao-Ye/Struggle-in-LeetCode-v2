#include <deque>
#include <unordered_map>

class MinStack
{
public:
    MinStack()
    {
        minimum_stack = {};
    }

    void push(int val)
    {
        if (minimum_stack.size() == 0 || val < minimum_stack.front().second)
        {
            minimum_stack.push_front({val, val});
        }
        else
        {
            minimum_stack.push_front({val, minimum_stack.front().second});
        }
    }

    void pop()
    {
        minimum_stack.pop_front();
    }

    int top()
    {
        return minimum_stack.front().first;
    }

    int getMin()
    {
        return minimum_stack.front().second;
    }

private:
    std::deque<std::pair<int, int>> minimum_stack;
};