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
    int max_cnt = 0, cur_cnt = 0, last;
    
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        return res;
    }
    
    // Time: O(n)
    // Space: O(h)
    void dfs(TreeNode * node) {
        if (!node) return;
        dfs(node->left);
        
        if (cur_cnt == 0) {
            // init
            ++cur_cnt;
            last = node->val;
        } else if (node->val == last) {
            ++cur_cnt;
        } else {
            // encounter a new number
            cur_cnt = 1;
            last = node->val;
        }
        
        if (cur_cnt > max_cnt) {
            res = {last};
            max_cnt = cur_cnt;
        } else if (cur_cnt == max_cnt) {
            res.push_back(last);
        }
        dfs(node->right);
    }
};
