#include <stack>
#include <queue>
#include <iostream>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool symmetric(TreeNode *left, TreeNode *right)
    {
        if (left && right && left->val == right->val)
        {
            return symmetric(left->left, right->right) && symmetric(left->right, right->left);
        }
        else if (left == nullptr && right == nullptr)
        {
            return true;
        }

        return false;
    }

    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }

        return symmetric(root->left, root->right);
    }

    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }

        std::queue<TreeNode *> q{};
        q.push(root->left);
        q.push(root->right);

        while (!q.empty())
        {
            int size = q.size();
            std::stack<TreeNode *> st{};

            for (int i = 0; i < size; i++)
            {
                auto node = q.front();
                q.pop();

                if (node)
                {
                    q.push(node->left);
                    q.push(node->right);
                }

                if (i < size / 2)
                {
                    st.push(node);
                }
                else
                {
                    auto mirror_node = st.top();
                    st.pop();

                    if (mirror_node && node && mirror_node->val != node->val)
                    {
                        return false;
                    }
                    else if ((mirror_node && node == nullptr) || (node && mirror_node == nullptr))
                    {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};