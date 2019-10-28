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
        stack<TreeNode*> s;
        TreeNode * p = root, *pre = nullptr;
        while (p || !s.empty()) {
            while (p) {
                s.push(p);
                p = p->left;
            }
            p = s.top(); 
            s.pop();
            if (pre && p->val <= pre->val) 
                return false;
            
            pre = p;
            p = p->right;
        }
        return true;
    }
};
