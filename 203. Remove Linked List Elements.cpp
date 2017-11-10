/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 
 1. dummy node
    dummy --> 1 -->  2  --> 6 --> 3 --> 4 --> 5 --> 6
                     prev        cur                                         

 
 2. pointer to pointer
 
    1 -->     2     -->    6       -->            3      --> 4 --> 5 --> 6    val = 6
    head           *node       (*node)->next
                    node
                    
    After iteration, head points to the first node not equal to 6
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode **node = &head;
        while (*node) {
            if ((*node)->val == val) {
                ListNode *tempNode = *node;
                *node = (*node)->next;
                delete tempNode;
            } else {
                node = &(*node)->next;
            }
        }
        return head;
    }
};
