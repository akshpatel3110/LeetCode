
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
        TreeNode * pre = nullptr;
        return inorder(root, pre);
    }
    
    bool inorder(TreeNode* node, TreeNode * & pre) {
        if (!node) 
            return true;
        
        if (!inorder(node->left, pre))
            return false;
        
        if (pre && node->val <= pre->val)
            return false;
        
        pre = node;
        return inorder(node->right, pre);
    }
};
