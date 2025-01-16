#include <vector>
#include <deque>

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
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        std::vector<std::vector<int>> output;
        std::deque<TreeNode *> dq;

        if (root)
        {
            dq.push_back(root);
        }

        bool forward = true;
        while (!dq.empty())
        {
            int size = dq.size();
            std::vector<int> row;

            for (int i = 0; i < size; i++)
            {
                if (forward)
                {
                    TreeNode *front = dq.front();
                    dq.pop_front();

                    row.push_back(front->val);

                    if (front->left)
                    {
                        dq.push_back(front->left);
                    }

                    if (front->right)
                    {
                        dq.push_back(front->right);
                    }
                }
                else
                {
                    TreeNode *back = dq.back();
                    dq.pop_back();

                    row.push_back(back->val);

                    if (back->right)
                    {
                        dq.push_front(back->right);
                    }

                    if (back->left)
                    {
                        dq.push_front(back->left);
                    }
                }
            }

            forward = !forward;
            output.push_back(row);
        }

        return output;
    }
};