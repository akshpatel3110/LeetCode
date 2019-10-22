/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Time O(n)
// Space O(n)        
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        
        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        
        ListNode * res = new ListNode(-1);
        int carry = 0;
        while (!s1.empty() || !s2.empty()) {
            int n1 = s1.empty() ? 0 : s1.top();
            int n2 = s2.empty() ? 0 : s2.top();
            int sum = n1 + n2 + carry;
            carry = sum / 10;
            
            // insert new node to the res->next
            ListNode * cur = new ListNode(sum % 10);
            cur->next = res->next;
            res->next = cur;
            if (!s1.empty())
                s1.pop();
            
            if (!s2.empty())
                s2.pop();
        }
        if (carry) {
            ListNode * cur = new ListNode(1);
            cur->next = res->next;
            res->next = cur;
        }
        
        return res->next;
    }
};
