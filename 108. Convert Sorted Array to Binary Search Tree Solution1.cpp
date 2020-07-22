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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(nums, 0, nums.size() - 1);
    }
    
    // Time: O(n)
    // Space: O(logn)
    TreeNode * dfs(const vector<int> & nums, int l, int r) {
        if (l > r)
            return nullptr;
        
        int m = l + (long long)r >> 1;
        auto node = new TreeNode(nums[m]);
        node->left = dfs(nums, l, m - 1);
        node->right = dfs(nums, m + 1, r);
        return node;
    }
};
