#include <stack>
#include <vector>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p)
    {
        std::stack<TreeNode *> st;
        std::vector<TreeNode *> visited;
        TreeNode *cur = root;

        while (cur != nullptr || !st.empty())
        {
            if (cur != nullptr)
            {
                st.push(cur);
                cur = cur->left;
            }
            else
            {
                cur = st.top();
                st.pop();

                if (!visited.empty() && visited.back() == p)
                {
                    return cur;
                }
                visited.push_back(cur);

                cur = cur->right;
            }
        }

        return nullptr;
    }

    TreeNode *inorderSuccessor_BST(TreeNode *root, TreeNode *p)
    {
        TreeNode *successor = nullptr;

        while (root != nullptr)
        {
            if (p->val >= root->val)
            {
                root = root->right;
            }
            else
            {
                successor = root;
                root = root->left;
            }
        }

        return successor;
    }
};