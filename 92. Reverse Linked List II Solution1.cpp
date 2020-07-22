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
    // Time: O(n)
    // Space: O(1)
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        auto dummy = new ListNode(0);
        dummy->next = head;
        auto p = dummy;
        for (int i = 0; i < m - 1; ++i)
            p = p->next;
        
        auto q = p->next, r = q->next;
        for (int i = 0; i < n - m; ++i) {
            auto t = r->next;
            r->next = q;
            q = r, r = t;
        }
        p->next->next = r;
        p->next = q;
        return dummy->next;
    }
};
