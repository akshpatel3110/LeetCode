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
    // Time: O(n)
    // Space: O(h)
    bool isBalanced(TreeNode* root) {
        if (dfs(root) == -1)
            return false;
        return true;
    }
    
    int dfs(TreeNode * node) {
        if (!node)
            return 0;
        
        int lh = dfs(node->left);
        if (lh == - 1)
            return -1;
        
        int rh = dfs(node->right);
        if (rh == -1)
            return -1;
        
        if (abs(lh - rh) > 1)
            return -1;
        
        return 1 + max(lh, rh);
    }
};
