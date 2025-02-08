#include <cmath>

typedef struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode *next) : val(x), next(next) {};
} ListNode_t;
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int m = 0, n = 0;

        ListNode *cur = headA;
        while (cur)
        {
            m++;
            cur = cur->next;
        }

        cur = headB;
        while (cur)
        {
            n++;
            cur = cur->next;
        }

        ListNode *longer_cur = m < n ? headB : headA;
        ListNode *shorter_cur = m < n ? headA : headB;

        for (int i = 0; i < std::abs(m - n); i++)
        {
            longer_cur = longer_cur->next;
        }

        while (longer_cur && shorter_cur)
        {
            if (longer_cur == shorter_cur)
            {
                return longer_cur;
            }

            longer_cur = longer_cur->next;
            shorter_cur = shorter_cur->next;
        }

        return nullptr;
    }
};