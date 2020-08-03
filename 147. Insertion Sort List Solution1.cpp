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
class Solution {
public:
    // Time: O(n ^ 2)
    // Space: O(1)
    ListNode* insertionSortList(ListNode* head) {
        auto dummy = new ListNode(-1), p = head;
        while (p) {
            auto cur = dummy, t = p->next;
            while (cur->next && cur->next->val <= p->val)
                cur = cur->next;
            
            p->next = cur->next;
            cur->next = p;
            p = t;
        }
        return dummy->next;
    }
};
