/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> m;
    
    Node* cloneGraph(Node* node) {
        if (!node)
            return nullptr;
        
        return dfs(node);
    }
    
    // Time: O(E)
    // Space: O(V)
    Node * dfs(Node * node) {
        if (m.count(node))
            return m[node];
        
        auto clone = new Node(node->val);
        m[node] = clone;
        for (auto neigh : node->neighbors) {
            clone->neighbors.push_back(dfs(neigh));
        }
        return clone;
    }
};
