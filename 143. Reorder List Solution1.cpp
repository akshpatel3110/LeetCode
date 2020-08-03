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
    void reorderList(ListNode* head) {
        // find the upper mid node
        int n = 0;
        for (auto p = head; p; p = p->next)
            ++n;
        
        if (n <= 2)
            return;
        
        auto mid = head;
        for (int i = 0; i < n / 2; ++i)
            mid = mid->next;
        
        // reverse the second half after upper_mid
        auto pre = mid, cur = mid->next;
        while (cur) {
            auto temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        
        // cur is the last node
        cur = pre;
        
        // if n is even, the last two nodes stay the same
        // if n is odd, the last node stay the same
        while (head->next != cur && head != cur) {
            auto temp = cur->next;
            cur->next = head->next;
            head->next = cur;
            cur = temp;
            head = head->next->next;
        }
        mid->next = nullptr;
    }
};
