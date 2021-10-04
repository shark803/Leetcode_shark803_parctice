//这道题是一个经典的二叉树重构问题，利用前序和中序遍历结果构建树
//原理非常简单，前序的第一个元素是根，在中序中找到
//这样中序遍历的vector，就以此元素拆分成左右子树
//根据中序得到的左右子树规模，前序也可以同样拆解
//这样本问题就转变成经典的树递归问题
//需要一个全局的map变量，记录中序的值-位置关系，来加速
//不放到全局变量，而作为参数，c++最后一个例子会超时

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
class Solution {
public:
    unordered_map<int,int> inmap;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++)
        {
            inmap[inorder[i]] = i;
        }
        int len = preorder.size() -1;
        TreeNode* root = buildMyTree(preorder, 0, len, inorder, 0, len);
        return root;
    }
    TreeNode* buildMyTree(vector<int>& preorder, int prestart, int preend, vector<int>&inorder, int instart, int inend)
    {
        if (prestart > preend || instart > inend){
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[prestart]);
        int root_position = inmap[root->val];
        int left_diff = root_position - instart;
        root->left = buildMyTree(preorder, prestart + 1, prestart + left_diff, inorder, instart, root_position - 1);
        root->right = buildMyTree(preorder, prestart+left_diff +1 , preend, inorder, root_position+1, inend);
        return root;
    }
};
