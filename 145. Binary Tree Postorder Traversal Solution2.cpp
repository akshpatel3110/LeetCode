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
        deque<int> res;
        stack<TreeNode*> s;
        TreeNode * p = root;
        while (p || !s.empty()) {
            if (p) {
                s.push(p);
                res.push_front(p->val);
                p = p->right;
            } else {
                p = s.top()->left; 
                s.pop();
            }
        }
        return vector<int>(res.begin(), res.end());
    }
};1
