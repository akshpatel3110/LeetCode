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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode * p = root;
        while (p || !s.empty()) {
            if (p) {
                s.push(p);
                res.push_back(p->val);
                p = p->left;
            } else {
                p = s.top()->right; 
                s.pop();
            }
        }
        return res;
    }
    
};
