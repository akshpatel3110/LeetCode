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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) 
            return {};
        
        vector<vector<int>> res;
        queue<TreeNode*> q{{root}};
        bool flag = true;
        while (q.size()) {
            int n = q.size();
            vector<int> level(n);
            for (int i = 0; i < n; ++i) {
                auto t = q.front(); 
                q.pop();
                int idx = flag ? i : (n - 1 - i);
                level[idx] = t->val;
                if (t->left) 
                    q.push(t->left);
                
                if (t->right) 
                    q.push(t->right);
            }
            flag = !flag;
            res.push_back(move(level));
        }
        return res;        
    }
};
