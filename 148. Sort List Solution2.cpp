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
    // Time: O(nlogn)
    // Space: O(1)
    ListNode* sortList(ListNode* head) {
        int n = 0;
        for (auto p = head; p; p = p->next)
            ++n;
        
        auto dummy = new ListNode(-1);
        dummy->next = head;
        for (int i = 1; i < n; i *= 2) {
            auto cur = dummy;
            for (int j = 1; j + i <= n; j += i * 2) {
                auto p = cur->next, q = p;
                for (int k = 0; k < i; ++k)
                    q = q->next;
                
                int x = 0, y = 0;
                while (x < i && y < i && p && q) {
                    if (p->val <= q->val) {
                        cur = cur->next = p;
                        p = p->next;
                        ++x;
                    } else {
                        cur = cur->next = q;
                        q = q->next;
                        ++y;
                    }
                }
                while (x < i && p) {
                        cur = cur->next = p;
                        p = p->next;
                        ++x;                    
                }
                while (y < i && q) {
                        cur = cur->next = q;
                        q = q->next;
                        ++y;                    
                }
                cur->next = q;
            }
        }
        return dummy->next;        
    }
};
