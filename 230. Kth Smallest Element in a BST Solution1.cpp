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
    int kthSmallest(TreeNode* root, int k) {
        return dfs(root, k);
    }
    
    // Time: O(k)
    // Space: O(min(k, h))
    int dfs(TreeNode * node, int & k) {
        if (!node)
            return -1;
        
        int res = dfs(node->left, k);
        if (k == 0)
            return res;
        
        if (--k == 0)
            return node->val;
        
        return dfs(node->right, k);
    }
    
};
