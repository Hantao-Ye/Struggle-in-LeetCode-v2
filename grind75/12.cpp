struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
        {
            return false;
        }

        ListNode *slow = head, *fast = head->next->next;
        while (fast != nullptr && slow != nullptr)
        {
            if (slow == fast)
            {
                return true;
            }

            fast = fast->next;
            slow = slow->next;

            if (fast == nullptr || fast->next == nullptr)
            {
                break;
            }
            fast = fast->next;
        }

        return false;
    }
};