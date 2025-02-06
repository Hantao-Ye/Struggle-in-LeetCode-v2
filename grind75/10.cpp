struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        TreeNode *ptr = root;
        while (ptr)
        {
            if (p->val < ptr->val && q->val < ptr->val)
            {
                ptr = ptr->left;
            }
            else if (p->val > ptr->val && q->val > ptr->val)
            {
                ptr = ptr->right;
            }
            else
            {
                break;
            }
        }

        return ptr;
    }

};