#include <stack>

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
    void inorder(TreeNode *root)
    {
        if (result != -1)
        {
            return;
        }

        if (root->left)
        {
            inorder(root->left);
        }

        index--;
        if (index == 0)
        {
            result = root->val;
            return;
        }

        if (root->right)
        {
            inorder(root->right);
        }
    }

    int kthSmallest(TreeNode *root, int k)
    {
        index = k;
        result = -1;

        inorder(root);

        return result;
    }

    int kthSmallestIterative(TreeNode *root, int k)
    {
        if (root == nullptr)
        {
            return -1;
        }

        std::stack<TreeNode *> stack;
        TreeNode *cur = root;

        int count = k;

        while (cur != nullptr || !stack.empty())
        {
            if (cur != nullptr)
            {
                stack.push(cur);
                cur = cur->left;
            }
            else
            {
                cur = stack.top();
                stack.pop();
                k--;

                if (k == 0)
                {
                    return cur->val;
                }

                cur = cur->right;
            }
        }

        return -1;
    }

private:
    int index;
    int result;
};