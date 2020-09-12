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
    // Time: O(h) only recurse to one branch
    // Space: O(h)
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return nullptr;
        
        if (root->val > max(p->val, q->val))
            return lowestCommonAncestor(root->left, p, q);
        
        if (root->val < min(p->val, q->val))
            return lowestCommonAncestor(root->right, p, q);
        
        return root;
    }
};
