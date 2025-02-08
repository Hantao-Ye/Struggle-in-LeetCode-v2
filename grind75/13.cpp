#include <stack>

class MyQueue
{
public:
    MyQueue()
    {
        left = std::stack<int>();
        right = std::stack<int>();
    }

    void push(int x)
    {
        right.push(x);
    }

    int pop()
    {
        if (!left.empty())
        {
            int top = left.top();
            left.pop();

            return top;
        }

        move();

        if (!left.empty())
        {
            int top = left.top();
            left.pop();

            return top;
        }

        return -1;
    }

    int peek()
    {
        if (!left.empty())
        {
            int top = left.top();

            return top;
        }

        move();

        if (!left.empty())
        {
            int top = left.top();

            return top;
        }

        return -1;
    }

    bool empty()
    {
        return left.empty() && right.empty();
    }

private:
    std::stack<int> left, right;

    void move()
    {
        while (!right.empty())
        {
            int top = right.top();
            right.pop();

            left.push(top);
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */