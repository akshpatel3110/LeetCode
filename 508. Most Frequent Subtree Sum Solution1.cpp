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
    vector<int> res;
    unordered_map<int, int> hash;
    int max_cnt = 0;
    
    // Time: O(n)
    // Space: O(n)
    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);
        return res;
    }
    
    int dfs(TreeNode * node) {
        if (!node) return 0;
        int sum = node->val + dfs(node->left) + dfs(node->right);
        ++hash[sum];
        if (hash[sum] > max_cnt) {
            max_cnt = hash[sum];
            res = {sum};
        } else if (hash[sum] == max_cnt) {
            res.push_back(sum);
        }
        return sum;
    }
};
