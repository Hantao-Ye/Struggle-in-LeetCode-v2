typedef struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode *next) : val(x), next(next) {};
} ListNode_t;

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *dummy_head = new ListNode(0, head);

    ListNode *pre_slow_ptr = dummy_head;
    ListNode *slow_ptr = head;
    ListNode *fast_ptr = head;

    for (int i = 0; i < n - 1; i++)
    {
        fast_ptr = fast_ptr->next;
    }

    while (fast_ptr->next != nullptr)
    {
        pre_slow_ptr = pre_slow_ptr->next;
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next;
    }

    pre_slow_ptr->next = slow_ptr->next;

    return dummy_head->next;
}