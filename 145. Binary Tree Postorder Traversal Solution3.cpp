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
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) 
            return {};
        
        deque<int> res;
        stack<TreeNode*> s{{root}};
        while (!s.empty()) {
            TreeNode * p = s.top(); 
            s.pop();
            res.push_front(p->val);
            if (p->left) 
                s.push(p->left);
            
            if (p->right) 
                s.push(p->right);
        }
        return vector<int>(res.begin(), res.end());
    }
};
