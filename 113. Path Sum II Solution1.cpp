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
    vector<vector<int>> res;
    vector<int> path;
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        dfs(root, sum);
        return res;
    }
    
    void dfs(TreeNode * node, int sum) {
        if (!node) return;
        path.push_back(node->val);
        sum -= node->val;
        if (!node->left && !node->right && !sum)
            res.push_back(path);
        
        dfs(node->left, sum);
        dfs(node->right, sum);
        path.pop_back();
    }
    
};
