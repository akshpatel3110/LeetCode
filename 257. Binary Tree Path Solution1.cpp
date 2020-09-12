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
    vector<string> res;
    vector<int> path;
    
    // Time: O(n ^ 2)
    // Space: O(h)
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root)
            dfs(root);
        return res;
    }
    
    void dfs(TreeNode * node) {
        path.push_back(node->val);
        if (!node->left && !node->right) {
            string s = to_string(path[0]);
            for (int i = 1; i < path.size(); ++i) {
                s += "->" + to_string(path[i]);
            }
            res.push_back(move(s));
        } else {
            if (node->left) dfs(node->left);
            if (node->right) dfs(node->right);
        }
        path.pop_back();
    }
};
