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
    // Space: O(1)
    bool isValidBST(TreeNode* root) {
        if (!root) 
            return true;
        
        TreeNode *cur = root, *pre, *parent = nullptr;
        bool res = true;
        while (cur) {
            if (!cur->left) {
                if (parent && parent->val >= cur->val) 
                    res = false;
                
                parent = cur;
                cur = cur->right;
            } else {
                pre = cur->left;
                while (pre->right && pre->right != cur) 
                    pre = pre->right;
                
                if (!pre->right) {
                    pre->right = cur;
                    cur = cur->left;
                } else {
                    pre->right = nullptr;
                    if (parent->val >= cur->val) 
                        res = false;
                    
                    parent = cur;
                    cur = cur->right;
                }
            }
        }
        return res;
    }
};
