#include <vector>

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    void connect_recursive(Node *root, Node *next)
    {
        if (root != nullptr)
        {
            root->next = next;

            if (root->left != nullptr && root->right != nullptr)
            {
                connect_recursive(root->left, root->right);
                connect_recursive(root->right, next != nullptr ? next->left : nullptr);
            }
        }
    }

    void connect_iterative(Node *root)
    {
        if (root == nullptr)
        {
            return;
        }

        Node *leftmost = root;
        while (leftmost->left != nullptr)
        {
            Node *node = leftmost;
            while (node != nullptr)
            {
                node->left->next = node->right;

                if (node->next != nullptr)
                {
                    node->right->next = node->next->left;
                }

                node = node->left;
            }

            leftmost = leftmost->left;
        }
    }

    Node *connect(Node *root)
    {
        connect_recursive(root, nullptr);
        return root;
    }
};