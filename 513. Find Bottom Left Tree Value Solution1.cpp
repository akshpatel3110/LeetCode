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
    int res, max_d = 0;
    
    // Time: O(n)
    // Space: O(h)
    int findBottomLeftValue(TreeNode* root) {
        dfs(root, 1);
        return res;
    }
    
    void dfs(TreeNode * node, int d) {
        if (!node) return;
        if (d > max_d) {
            max_d = d;
            res = node->val;
        }
        dfs(node->left, d + 1);
        dfs(node->right, d + 1);
    }
};
