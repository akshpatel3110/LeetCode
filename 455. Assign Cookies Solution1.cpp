// Time: O(glogg + slogs + s + g) = O(glogg + slogs)
// Space: O(1)
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j = 0, res = 0;
        while (j < s.size()) {
            if (s[j] >= g[i]) {
                ++res;
                ++i; // next children
            }
            if (i == g.size())
                break;
            ++j;
        }
        return res;
    }
};
