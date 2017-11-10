/*

At the top
LCA(3, 6, 8)  left 6, right 8 --> I am the the LCA : 3
LCA(3, 5, 4)  left 5, right nullptr --> what my left subtree returns is the LCA : 5
LCA(3, 1, 0)  left nullptr, right 1 --> what my right subtree returns is the LCA : 1

During the recursive call: LCA(2, 6, 0) --> left nullptr, right subtree nullptr --> I will return nullptr.

Base Case 1: root is nullptr --> return nullptr
Base Case 2: LCA(5, 5, 8) --> ignore everything under me, return myself
             LCA(5, 8, 5) --> ignore everything under me, return myself


o(n) time: In the worst case, traverse every node
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        if (left && right) {
            return root;
        } else if (left && !right) {
            return left;
        } else if (!left && right) {
            return right;
        } else {
            return nullptr;
        }
    }
};
