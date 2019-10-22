/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Time: O(n)
// Space: O(n)
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * res = new ListNode(1); // 1 if there is carry 
        int n1 = getLength(l1);
        int n2 = getLength(l2);
        res->next = (n1 > n2) ? helper(l1, l2, n1 - n2) : helper(l2, l1, n2 - n1);
        
        // check carry
        if (res->next->val > 9) {
            res->next->val %= 10;
            return res;
        }
        
        // no carry
        return res->next;
    }
    
    int getLength(ListNode * node) {
        int len = 0;
        while (node) {
            ++len;
            node = node->next;
        }
        return len;
    }
    
    ListNode* helper(ListNode * l1, ListNode * l2, int diff) {
        if (!l1) 
            return nullptr;
        
        ListNode * left = (diff == 0) ? new ListNode(l1->val + l2->val) : new ListNode(l1->val);
        ListNode * right = (diff == 0) ? helper(l1->next, l2->next, 0) : helper(l1->next, l2, diff - 1);
        if (right && right->val > 9) {
            right->val %= 10;
            ++left->val;
        }
        left->next = right;
        return left;
    }
};
