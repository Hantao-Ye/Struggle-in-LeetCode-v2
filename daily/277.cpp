#include <iostream>
#include <unordered_set>

class Solution
{
public:
    // my initial thought for logical reduction
    int findCelebrity(int n)
    {
        std::unordered_set<int> set{};

        for (int i = 0; i < n; i++)
        {
            set.insert(i);
        }

        while (!set.empty())
        {
            int celebrity = *set.begin();
            int other = 0;

            for (; other < n; other++)
            {
                if (other == celebrity)
                {
                    continue;
                }

                if (knows(other, celebrity))
                {
                    set.erase(other);
                }
                else
                {
                    set.erase(celebrity);
                    break;
                }

                if (knows(celebrity, other))
                {
                    set.erase(celebrity);
                    break;
                }
            }

            if (other == n)
                return celebrity;
        }

        return -1;
    }
    // after check the editorial
    int findCelebrity_example(int n)
    {
        int celebrity = 0;
        for (int i = 1; i < n; i++)
        {
            if (knows(celebrity, i))
            {
                celebrity = i;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if ((i != celebrity && knows(celebrity, i)) || (!knows(i, celebrity)))
            {
                return -1;
            }
        }

        return celebrity;
    }

private:
    bool knows(int a, int b);
};