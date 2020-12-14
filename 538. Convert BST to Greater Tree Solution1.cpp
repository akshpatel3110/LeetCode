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
    int s = 0;
    
    // Time: O(n)
    // Space: O(h)
    TreeNode* convertBST(TreeNode* root) {
        dfs(root);
        return root;
    }
    
    void dfs(TreeNode * node) {
        if (!node) return;
        dfs(node->right);
        int x = node->val;
        node->val += s;
        s += x;
        dfs(node->left);
    }
};
