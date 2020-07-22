/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    // Time: O(nlogn)
    // Space: O(logn)
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head)
            return nullptr;
        
        int n = 0;
        for (auto p = head; p; p = p->next)
            ++n;
        
        if (n == 1)
            return new TreeNode(head->val);
        
        auto cur = head;
        for (int i = 0; i < n / 2 - 1; ++i)
            cur = cur->next;
        
        auto node = new TreeNode(cur->next->val);
        node->right = sortedListToBST(cur->next->next);
        cur->next = nullptr;
        node->left = sortedListToBST(head);
        return node;
    }
};
