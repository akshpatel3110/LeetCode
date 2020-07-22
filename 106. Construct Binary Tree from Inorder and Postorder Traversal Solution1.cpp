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
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); ++i)
            m[inorder[i]] = i;
        
        return dfs(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
    
    TreeNode *dfs(const vector<int> & inorder, const vector<int> & postorder,
                  int il, int ir, int pl, int pr) {
        if (il > ir)
            return nullptr;
        
        auto node = new TreeNode(postorder[pr]);
        int k = m[node->val];
        node->left = dfs(inorder, postorder, il, k - 1, pl, pl + k - 1 - il);
        node->right = dfs(inorder, postorder, k + 1, ir, pl + k - il, pr - 1);
        return node;
    }
};
