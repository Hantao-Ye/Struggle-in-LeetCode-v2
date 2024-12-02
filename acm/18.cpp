#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode *next) : val(val), next(next) {}
};

std::pair<bool, int> get_list_node(ListNode *root, int idx)
{
    auto cur = root;

    while (idx > 1)
    {
        if (cur == nullptr)
        {
            return {false, -1};
        }

        cur = cur->next;
        idx--;
    }

    return {true, cur->val};
}

bool delete_list_node(ListNode *dummy_head, ListNode *root, int idx)
{
    ListNode *prev = dummy_head;
    ListNode *cur = root;

    while (idx > 1)
    {
        if (cur == nullptr)
        {
            return false;
        }

        prev = cur;
        cur = cur->next;

        idx--;
    }

    prev->next = cur->next;
    delete (cur);

    return true;
}

bool insert_list_node(ListNode *dummy_head, ListNode *root, int idx, int val)
{
    ListNode *prev = dummy_head;
    ListNode *cur = root;

    while (idx > 1)
    {
        if (cur == nullptr)
        {
            return false;
        }

        prev = cur;
        cur = cur->next;

        idx--;
    }

    ListNode *inserted_node = new ListNode(val, cur);
    prev->next = inserted_node;

    return true;
}

std::string show_list_node(ListNode *root)
{
    auto cur = root;

    std::string output{};

    while (cur != nullptr)
    {
        output += std::to_string(cur->val);
        output.push_back(' ');

        cur = cur->next;
    }

    if (output.size() > 0)
    {
        output.pop_back();
    }
    else
    {
        output = "Link list is empty";
    }

    return output;
}

int main()
{
    ListNode *dummy_head = new ListNode(0);

    int node_num(0), command_num(0);
    std::string command{};

    std::cin >> node_num;

    for (int i = 0; i < node_num; i++)
    {
        int node_val(0);
        std::cin >> node_val;

        insert_list_node(dummy_head, dummy_head->next, 1, node_val);
    }

    std::cin >> command_num;

    for (int i = 0; i < command_num; i++)
    {
        std::cin >> command;
        if (command == "get")
        {
            int idx(0);
            std::cin >> idx;

            auto result = get_list_node(dummy_head->next, idx);

            if (result.first)
            {
                std::cout << result.second << std::endl;
            }
            else
            {
                std::cout << "get fail" << std::endl;
            }
        }
        else if (command == "insert")
        {
            int idx(0), val(0);
            std::cin >> idx >> val;

            auto result = insert_list_node(dummy_head, dummy_head->next, idx, val);
            if (result)
            {
                std::cout << "insert OK" << std::endl;
            }
            else
            {
                std::cout << "insert fail" << std::endl;
            }
        }
        else if (command == "delete")
        {
            int idx(0);
            std::cin >> idx;

            auto result = delete_list_node(dummy_head, dummy_head->next, idx);
            if (result)
            {
                std::cout << "delete OK" << std::endl;
            }
            else
            {
                std::cout << "delete fail" << std::endl;
            }
        }
        else if (command == "show")
        {
            std::cout << show_list_node(dummy_head->next) << std::endl;
        }
    }

    return 0;
}