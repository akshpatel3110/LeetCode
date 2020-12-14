/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    // Time: O(n)
    // Space: O(h)
    int maxDepth(Node* root) {
        if (!root) return 0;
        int res = 0;
        for (auto c : root->children)
            res = max(res, maxDepth(c));
        return res + 1;
    }
};
