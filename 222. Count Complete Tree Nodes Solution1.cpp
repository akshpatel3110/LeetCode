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
    // Time: O(logn * logn)
    // Space: O(logn)
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        auto l = root->left, r = root->right;
        int lh = 1, rh = 1;
        while (l) {
            l = l->left;
            ++lh;
        }
        while (r) {
            r = r->right;
            ++rh;
        }
        if (lh == rh) return (1 << lh) - 1;
        return countNodes(root->left) + 1 + countNodes(root->right);
    }
};
