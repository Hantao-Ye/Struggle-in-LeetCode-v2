#include <vector>
#include <unordered_map>

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
    TreeNode *buildInorderTree(std::vector<int> &preorder, std::vector<int> &inorder, int left, int right)
    {
        if (left > right)
        {
            return nullptr;
        }

        int root_val = preorder[preorder_idx++];

        TreeNode *root = new TreeNode(root_val);
        root->left = buildInorderTree(preorder, inorder, left, inorder_map[root_val] - 1);
        root->right = buildInorderTree(preorder, inorder, inorder_map[root_val] + 1, right);

        return root;
    }

    TreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder)
    {
        preorder_idx = 0;
        for (int i = 0; i < inorder.size(); i++)
        {
            inorder_map[inorder[i]] = i;
        }

        return buildInorderTree(preorder, inorder, 0, inorder.size() - 1);
    }

private:
    int preorder_idx;
    std::unordered_map<int, int> inorder_map;
};