//本质是一个二叉树中序遍历的问题，二叉搜索树中序遍历是有序序列
//交换两个节点，破坏了有序性
//中序可以显性或者隐性的去找到这两个节点
//两两比较，第一个不满足顺序的为first， 最后一个不满足为second
//无论用递归还是迭代还是morris，均可以实现

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
   TreeNode* pred = nullptr, *first = nullptr, *second = nullptr;
    void recoverTree(TreeNode* root) {
              inorder_traverse(root);
              swap(first->val, second->val);
    }
    void inorder_traverse(TreeNode* root){
        if (root == nullptr){
            return;
        }
        inorder_traverse (root->left);
        if (pred == nullptr){
            pred = root;
        } else {
            if (pred -> val > root->val) {
                if (first == nullptr) {
                    first = pred;
                }
                second = root;
            }
            pred = root;
        }
        inorder_traverse (root->right);
    }
}; 
