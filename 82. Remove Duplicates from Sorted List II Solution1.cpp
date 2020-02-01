/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        auto dummy = new ListNode(-1);
        dummy->next = head;
        auto pre = dummy;
        while (pre->next) {
            auto node = pre->next;
            while (node->next && node->val == node->next->val) {
                node = node->next;
            }
            
            if (node == pre->next) {
                pre = pre->next;
            } else {
                pre->next = node->next;
            }
        }
        return dummy->next;
    }
};
