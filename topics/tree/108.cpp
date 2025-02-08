#include <vector>
#include <queue>
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
    TreeNode *sortedArrayToBST(std::vector<int> &nums)
    {
        return arrayToBST(nums, 0, nums.size() - 1);
    }

    TreeNode *arrayToBST(std::vector<int> &nums, int start, int end)
    {
        if (start > end)
        {
            return nullptr;
        }
        else if (start == end)
        {
            return new TreeNode(nums[start]);
        }

        int mid = start + (end - start) / 2;

        auto node = new TreeNode(nums[mid]);
        node->left = arrayToBST(nums, start, mid - 1);
        node->right = arrayToBST(nums, mid + 1, end);

        return node;
    }
};