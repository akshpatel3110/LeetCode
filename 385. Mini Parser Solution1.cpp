/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int u;
    
    // Time: O(n)
    // Space: O(n)
    NestedInteger deserialize(string s) {
        return dfs(s);
    }
    
    NestedInteger dfs(string & s) {
        NestedInteger res;
        if (s[u] == '[') { // internal node
            ++u; // skip '['
            while (s[u] != ']') res.add(dfs(s));
            
            ++u; // skip ']'
            if (u < s.size() && s[u] == ',') ++u;
        } else { // leaf node
            int i = u;
            while (i < s.size() && s[i] != ',' && s[i] != ']')
                ++i;
            
            res.setInteger(stoi(s.substr(u, i - u)));
            if (i < s.size() && s[i] == ',') ++i;
            u = i;
        }
        return res;
    }
};
