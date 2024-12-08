#include <iostream>
#include <sstream>
#include <vector>
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
    std::vector<int> inorderTraversal(TreeNode *root)
    {
        std::vector<int> output{};

        traverse(root, output);

        return output;
    }

    std::vector<int> inorderTraversalIter(TreeNode *root)
    {
        std::vector<int> result{};
        std::stack<TreeNode *> stack{};

        if (root != nullptr)
        {
            stack.push(root);
        }

        while (!stack.empty())
        {
            auto node = stack.top();
            if (node != nullptr)
            {
                stack.pop();

                if (node->right != nullptr)
                {
                    stack.push(node->right);
                }
                stack.push(node);
                stack.push(nullptr);
                if (node->left != nullptr)
                {
                    stack.push(node->left);
                }
            }
            else
            {
                stack.pop();
                node = stack.top();
                stack.pop();

                result.push_back(node->val);
            }
        }

        return result;
    }

private:
    void traverse(TreeNode *root, std::vector<int> &output)
    {
        if (root == nullptr)
        {
            return;
        }

        traverse(root->left, output);
        output.push_back(root->val);
        traverse(root->right, output);
    }
};
