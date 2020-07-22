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
    TreeNode * pre = nullptr, *first = nullptr, *second = nullptr;
    
    void recoverTree(TreeNode* root) {
        dfs(root);
        swap(first->val, second->val);
    }
    
    // Time: O(n)
    // Space: O(h)
    void dfs(TreeNode* node) {
        if (!node) 
            return;
        
        dfs(node->left);
        if (!pre) {
            pre = node;
        } else {
            if (pre->val > node->val) {
                if (!first)
                    first = pre;
                second = node;
            }
            pre = node;
        }
        dfs(node->right);
    }
};
