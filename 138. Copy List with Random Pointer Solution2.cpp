/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    // Time: O(n)
    // Space: O(1)
    Node* copyRandomList(Node* head) {
        // clone
        for (auto p = head; p; p = p->next->next) {
            auto q = new Node(p->val);
            q->next = p->next;
            p->next = q;
        }
        
        // copy random pointer
        for (auto p = head; p; p = p->next->next) {
            if (p->random)
                p->next->random = p->random->next;
        }
        
        // extract out two lists
        auto dummy = new Node(0), cur = dummy;
        for (auto p = head; p; p = p->next) {
            auto q = p->next;
            cur = cur->next = q;
            p->next = q->next;
        }
        return dummy->next;
    }
};
