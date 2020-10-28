/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        auto res = dfs(head);
        return res.first;
    }
    
    // Time: O(n)
    // Space: O(h)
    pair<Node*, Node*> dfs(Node * head) {
        if (!head) return {nullptr, nullptr};
        auto cur = head, tail = head; // cur might be nullptr, but tail cannot be, diff by 1 at the end of each iteration
        while (cur) {
            tail = cur;
            if (cur->child) {
                auto t = dfs(cur->child);
                cur->child = nullptr;
                t.second->next = cur->next;
                if (cur->next) cur->next->prev = t.second;
                cur->next = t.first;
                t.first->prev = cur;
                tail = t.second;
                cur = t.second->next;
            } else {
                cur = cur->next;
            }
        }
        return {head, tail};
        
    }
};
