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
    TreeNode * res = nullptr;
    
    // Time: O(n)
    // Space: O(h)
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return res;
    }
    
    int dfs(TreeNode * root, TreeNode * p, TreeNode * q) {
        if (!root) return 0;
        int state = 0;
        if (root == p) state |= 1;
        else if (root == q) state |= 2;        
        state |= dfs(root->left, p, q);
        state |= dfs(root->right, p, q);
        if (state == 3 && !res) res = root; // this is where the lowest comes
        return state;
    }
    
};
