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
    // Space: O(2 ^ (h - 1))
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) 
            return {};
        
        vector<vector<int>> res;
        queue<TreeNode*> q{{root}};
        while (q.size()) {
            int n = q.size();
            vector<int> level;
            while (n--) {
                auto t = q.front(); 
                q.pop();
                level.push_back(t->val);
                if (t->left) 
                    q.push(t->left);
                
                if (t->right) 
                    q.push(t->right);
            }
            res.push_back(move(level));
        }
        return res;
    }
};
