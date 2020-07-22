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
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root)
            return false;
        
        sum -= root->val;
        if (!root->left && !root->right)
            return !sum;
        
        return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
    }
};
