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
        if (!head)
            return head;
        
        auto p = head;
        while (p->next) {
            if (p->val == p->next->val) {
                auto node = p->next;
                p->next = node->next;
                delete node;
            } else {
                p = p->next;
            }
        }
        return head;
    }
};
