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
    ListNode* removeElements(ListNode* head, int val) {
        auto dummy = new ListNode(-1);
        dummy->next = head;
        auto pre = dummy;
        while (pre) {
            auto cur = pre->next;
            while (cur && cur->val == val)
                cur = cur->next;
            
            if (cur != pre->next) {
                pre->next = cur;
            }
            pre = cur;
        }
        return dummy->next;
        
    }
};
