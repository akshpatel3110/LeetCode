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
    int res = 0;
    unordered_map<int, int> hash; // key is prefix sum, value is count
    
    int pathSum(TreeNode* root, int sum) {
        ++hash[0];
        dfs(root, sum, 0);
        return res;
    }
    
    // Time: O(n)
    // Space: O(n)
    // variation of two sum
    void dfs(TreeNode * node, int sum, int cur) {
        if (!node) return;
        cur += node->val;
        res += hash[cur - sum];
        ++hash[cur];
        dfs(node->left, sum, cur);
        dfs(node->right, sum, cur);
        --hash[cur];
    }
};
