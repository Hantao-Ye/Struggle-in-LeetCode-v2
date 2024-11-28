#include <iostream>
#include <stack>
#include <climits>

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
    bool validate(TreeNode *node, TreeNode *low, TreeNode *high)
    {
        if (node == nullptr)
        {
            return true;
        }

        if ((low && node->val <= low->val) or (high && node->val >= high->val))
        {
            return false;
        }

        return validate(node->left, low, node) && validate(node->right, node, high);
    }

    bool isValidBST(TreeNode *root)
    {
        return validate(root, nullptr, nullptr);
    }

    bool isValidBSTInorder(TreeNode *root)
    {
        std::stack<TreeNode *> st{};
        std::pair<bool, int> prev{false, INT_MIN};

        if (root)
        {
            st.push(root);
        }

        while (!st.empty())
        {
            TreeNode *node = st.top();
            st.pop();
            if (node != nullptr)
            {
                if (node->right)
                {
                    st.push(node->right);
                }

                st.push(node);
                st.push(nullptr);

                if (node->left)
                {
                    st.push(node->left);
                }
            }
            else
            {
                node = st.top();
                st.pop();

                if (!prev.first || node->val > prev.second)
                {
                    prev.first = true;
                    prev.second = node->val;
                }
                else
                {
                    return false;
                }
            }
        }

        return true;
    }
};