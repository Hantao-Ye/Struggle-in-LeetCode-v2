

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode *next) : val(val), next(next) {}
};

class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
        {
            return head;
        }

        ListNode *even_head = head->next;

        ListNode *first = head;
        ListNode *second = head->next;

        while (second && second->next)
        {
            first->next = second->next;
            second->next = second->next->next;

            first = first->next;
            second = second->next;
        }

        first->next = even_head;

        return head;
    }
};
