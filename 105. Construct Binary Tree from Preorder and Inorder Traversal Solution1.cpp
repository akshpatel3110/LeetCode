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
    
    unordered_map<int, int> m;
    
    // Time: O(n)
    // Space: O(n)
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); ++i)
            m[inorder[i]] = i;
        
        return dfs(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
    
    TreeNode *dfs(const vector<int> & preorder, const vector<int> &inorder,
                  int pl, int pr, int il, int ir) {
        if (pl > pr)
            return nullptr;
        
        auto node = new TreeNode(preorder[pl]);
        int k = m[node->val];
        node->left = dfs(preorder, inorder, pl + 1, pl + k - il, il, k - 1);
        node->right = dfs(preorder, inorder, pl + k - il + 1, pr, k + 1, ir);
        return node;
    }
};
