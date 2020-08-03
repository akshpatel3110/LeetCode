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
    // Recursive Solution
    // Time: O(nlogn)
    // Space: O(logn)
    ListNode* sortList(ListNode* head) {
        int n = 0;
        for (auto p = head; p; p = p->next)
            ++n;
        
        if (n <= 1)
            return head;
        
        auto mid = head;
        for (int i = 0; i < (n - 1) / 2; ++i)
            mid = mid->next;
        
        auto l2 = mid->next;
        mid->next = nullptr;
        return merge(sortList(head), sortList(l2));     
    }
    
    ListNode * merge(ListNode * l1, ListNode * l2) {
        auto dummy = new ListNode(-1), cur = dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if (l1) cur->next = l1;
        if (l2) cur->next = l2;
        return dummy->next;
    }
};
