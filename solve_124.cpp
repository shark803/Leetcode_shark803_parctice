/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//求最大路径 本质上可以看出后序遍历
// 唯一的变化是 左侧子路径和右侧子路径是否为负数，如果选取单侧路径，另一侧置0
// 最终路径长度可以设置为一个全局遍历，遍历过程累积


class Solution {
public:
    int  ans = INT_MIN;
    int maxPathSum(TreeNode* root) {
           onesideMax(root);
            return ans;
    }
    int onesideMax(TreeNode* root)
    {
        if (root == nullptr) {
            return 0;
        }
        int left = max(0, onesideMax(root->left));
        int right = max (0, onesideMax(root->right));

        ans = max(ans, left + right + root->val);
        return max(left, right) + root->val;
    }
};

