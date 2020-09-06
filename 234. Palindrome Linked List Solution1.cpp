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
    bool isPalindrome(ListNode* head) {
        int n = 0;
        for (auto p = head; p; p = p->next)
            ++n;
        
        if (n <= 1)
            return true;
        
        // reverse the second half
        auto a = head;
        for (int i = 0; i < (n - 1) / 2; ++i)
            a = a->next;
        
        auto b = a->next;
        while (b) {
            auto c = b->next;
            b->next = a;
            a = b;
            b = c;
        }
        
        // check palindrome
        auto tail = a;
        b = head;
        bool res = true;
        for (int i = 0; i < n / 2; ++i) {
            if (a->val != b->val) {
                res = false;
                break;
            }
            a = a->next;
            b = b->next;
        }
        
        // reverse the second half back
        a = tail;
        b = a->next;
        for (int i = 0; i < n / 2; ++i) {
            auto c = b->next;
            b->next = a;
            a = b;
            b = c;
        }
        tail->next = nullptr;
        return res;
    }
};
