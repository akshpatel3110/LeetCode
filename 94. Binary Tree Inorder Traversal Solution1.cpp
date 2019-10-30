/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Time: O(n)
// Space: O(h)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        dfs(root, res);
        return res;
    }
    
    void dfs(TreeNode * node, vector<int> & res) {
        if (!node) 
            return;
        
        if (node->left) 
            dfs(node->left, res);
        
        res.push_back(node->val);
        if (node->right) 
            dfs(node->right, res);
    }
};
