/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // Time: O(n)
    // Space: O(h)
    bool isValidBST(TreeNode* root) {
        return dfs(root, LLONG_MIN, LLONG_MAX);
    }
    
    bool dfs(TreeNode * root, long long minv, long long maxv) {
        if (!root)
            return true;
        
        // check current node, should fall in (minv, maxv)
        if (root->val <= minv || root->val >= maxv)
            return false;
        
        return dfs(root->left, minv, root->val) &&
               dfs(root->right, root->val, maxv);
    }
};
