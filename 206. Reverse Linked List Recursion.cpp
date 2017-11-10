/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 
// Base Case 1 : head is nullptr
// Base Case 2 : single node

    // 1 --> 2 <-- 3
     head         res

 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode * res = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return res;
    }
};
