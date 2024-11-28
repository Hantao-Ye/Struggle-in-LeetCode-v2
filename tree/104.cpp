#include <iostream>
#include <queue>

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
    // recursive
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        int left_depth = maxDepth(root->left);
        int right_depth = maxDepth(root->right);

        return 1 + left_depth > right_depth ? left_depth : right_depth;
    }
    // iterating
    int maxDepthIter(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        std::queue<TreeNode *> q = std::queue<TreeNode *>{};
        q.push(root);

        int depth = 0;

        while (!q.empty())
        {
            int size = q.size();
            depth++;

            for (int i = 0; i < size; i++)
            {
                auto node = q.front();
                q.pop();

                if (node->left != nullptr)
                {
                    q.push(node->left);
                }
                if (node->right != nullptr)
                {
                    q.push(node->right);
                }
            }
        }

        return depth;
    }
};