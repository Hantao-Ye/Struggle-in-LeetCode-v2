#include <queue>
#include <vector>

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
    std::vector<std::vector<int>> levelOrder(TreeNode *root)
    {
        std::vector<std::vector<int>> output{};

        std::queue<TreeNode *> q{};
        if (root)
        {
            q.push(root);
        }

        while (!q.empty())
        {
            std::vector<int> output_layer{};

            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                auto node = q.front();
                q.pop();

                output_layer.push_back(node->val);

                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
            }

            output.push_back(output_layer);
        }

        return output;
    }
};