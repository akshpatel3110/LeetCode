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
    ListNode* partition(ListNode* head, int x) {
        auto ld = new ListNode(), rd = new ListNode();
        auto lt = ld, rt = rd;
        for (auto p = head; p; p = p->next) {
            if (p->val < x) {
                lt = lt->next = p;
            } else {
                rt = rt->next = p;
            }
        }
        lt->next = rd->next;
        rt->next = nullptr;
        return ld->next;
    }
};
