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
    // Space: O(n)
    Node* copyRandomList(Node* head) {
        auto dummy = new Node(-1), cur = dummy;
        unordered_map<Node*, Node*> m;
        
        // copy next pointer and fill mapping
        for (auto p = head; p; p = p->next) {
            auto t = new Node(p->val);
            cur = cur->next = t;
            m[p] = t;
        }
        
        // copy random pointer
        cur = dummy->next;
        for (auto p = head; p; p = p->next) {
            if (p->random)
                cur->random = m[p->random];
            cur = cur->next;
        }
        return dummy->next;
    }
};
