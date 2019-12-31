// Time: O(glogg + slogs + s + g) = O(glogg + slogs)
// Space: O(1)
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j = 0, res = 0;
        // fix a child
        while (i < g.size()) {
            // find the first cookie so that s[j] >= s[i]
            while (j < s.size() && s[j] < g[i])
                ++j;
            
            if (j == s.size())
                break;
            
            // assign to that child
            ++res;
            ++j;
            ++i;
        }
        return res;
    }
};
