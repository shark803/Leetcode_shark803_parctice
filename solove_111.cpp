//这道题既可以用BFS也可以用DFS，这里贴一个BFS的套路解法

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
    int minDepth(TreeNode* root) {
            queue<TreeNode*>  q;
            if (root == nullptr) return 0;
            int level =  1;
            q.push(root);
            while (!q.empty()){
                int size = q.size();
                for (int i=0; i< size; i++){
                    TreeNode* cur = q.front();
                    q.pop();
                    if (cur->left == nullptr && cur->right == nullptr){
                        return level;
                    }
                    if (cur->left){
                        q.push(cur->left);
                    }
                    if (cur->right){
                        q.push(cur->right);
                    }
                }
                level += 1;
            }
            return -1;
    }
};
