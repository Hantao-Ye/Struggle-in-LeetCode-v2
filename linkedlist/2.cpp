#include <iostream>
#include <sstream>

typedef struct ListNode
{
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode *next) : val(val), next(next) {}
} ListNode_t;

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int carry = 0;

        ListNode *dummy_head = new ListNode(0);
        ListNode *prev = dummy_head;

        while (l1 != nullptr && l2 != nullptr)
        {
            int digit = l1->val + l2->val + carry;

            carry = digit / 10;
            digit = digit % 10;

            ListNode *node = new ListNode(digit);
            prev->next = node;
            prev = prev->next;

            l1 = l1->next;
            l2 = l2->next;
        }

        if (l1 != nullptr || l2 != nullptr)
        {
            ListNode *list = (l1 != nullptr ? l1 : l2);

            while (list != nullptr)
            {
                int digit = list->val + carry;

                carry = digit / 10;
                digit = digit % 10;

                ListNode *node = new ListNode(digit);
                prev->next = node;
                prev = prev->next;

                list = list->next;
            }
        }

        if (carry != 0)
        {
            ListNode *node = new ListNode(carry);

            prev->next = node;
        }

        return dummy_head->next;
    }

    ListNode *createListNode(std::string str)
    {
        int val(0);
        std::istringstream iss(str);

        ListNode *dummy_head = new ListNode(0);
        ListNode *prev = dummy_head;

        while (iss >> val)
        {
            ListNode *node = new ListNode(val);
            prev->next = node;
            prev = node;
        }

        return dummy_head->next;
    }

    void printListNode(const ListNode *list)
    {
        const ListNode *cur = list;

        while (cur != nullptr)
        {
            std::cout << cur->val;

            if (cur->next == nullptr)
            {
                std::cout << std::endl;
            }
            else
            {
                std::cout << "->";
            }

            cur = cur->next;
        }

        return;
    }
};

int main()
{
    Solution s{};

    while (true)
    {
        std::string line{};
        std::getline(std::cin, line);

        if (line.size() == 0)
        {
            break;
        }

        auto l1 = s.createListNode(line);

        std::getline(std::cin, line);
        if (line.size() == 0)
        {
            break;
        }

        auto l2 = s.createListNode(line);

        auto l3 = s.addTwoNumbers(l1, l2);
        s.printListNode(l3);
    }

    return 0;
}