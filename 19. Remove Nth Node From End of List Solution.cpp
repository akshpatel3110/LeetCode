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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto dummy = new ListNode(-1);
        dummy->next = head;
        auto fast = dummy, slow = dummy;
        while (n--)
            fast = fast->next;
        
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        auto node = slow->next;
        slow->next = node->next;
        delete node;
        return dummy->next;
    }
};
