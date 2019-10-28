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
        return dfs(root, nullptr, nullptr);
    }
    
    bool dfs(TreeNode * node, int * minv, int * maxv) {
        if (!node)
            return true;
        
        if ((minv && node->val <= *minv) || (maxv && node->val >= *maxv))
            return false;
        
        return dfs(node->left, minv, &node->val) && dfs(node->right, &node->val, maxv);
    }
};
