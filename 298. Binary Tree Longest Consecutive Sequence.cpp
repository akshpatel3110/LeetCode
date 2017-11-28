/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
Maintain three variables:
	pathLen: current length of consecutive sequence path
	target: the expected value of current node if a consecutive sequence path including the current node is to be formed
    res:  the length of the longest consecutive sequence
    
Base case:
    Current node is nullptr, not a node within a consecutive path → return

During the recursion
    The value of current node is equal to target, increment pathLen by 1, otherwise reset to 1
    Update the res during the dfs traversal of the binary tree
    Recurse on the children of the current node.

*/

class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        int res = 0;
        // Set pathLen to zero since we haven't checked current node
        // The third param does not matter, it will always be set to 1 in the first recursion call
        dfs(root, 0, 0, res);
        return res;
    }
    
    void dfs(TreeNode* node, int pathLen, int target, int &res) {
        if (!node)
            return;
        
        if (node->val == target)
            ++pathLen;
        else
            pathLen = 1;
        
        res = max(pathLen, res);
        dfs(node->left, pathLen, node->val + 1, res);
        dfs(node->right, pathLen, node->val + 1, res);
    }
};
