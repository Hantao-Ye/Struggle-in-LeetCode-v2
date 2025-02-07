#include <algorithm>

struct TreeNode
{
    int val;
    TreeNode *left, *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right) {}
};

class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }

        if (std::abs(getDepth(root->left) - getDepth(root->right)) > 1)
        {
            return false;
        }

        return isBalanced(root->left) && isBalanced(root->right);
    }

    int getDepth(TreeNode *node)
    {
        if (node == nullptr)
        {
            return 0;
        }

        return 1 + std::max(getDepth(node->left), getDepth(node->right));
    }

    bool isBalancedHelper(TreeNode *node, int &height)
    {
        if (node == nullptr)
        {
            height = -1;
            return true;
        }

        int left, right;
        if (isBalancedHelper(node->left, left) && isBalancedHelper(node->right, right) && std::abs(left - right) < 2)
        {
            height = std::max(left, right) + 1;
            return true;
        }

        return false;
    }
};
