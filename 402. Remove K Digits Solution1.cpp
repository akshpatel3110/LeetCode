class Solution {
public:
    // Time: O(n)
    // Space: O(n)
    string removeKdigits(string num, int k) {
        // greedy
        k = min(k, (int)num.size());
        string res;
        for (auto c : num) {
            while (k && res.size() && res.back() > c) {
                --k;
                res.pop_back();
            }
            res += c;
        }
        
        // delete the last k chars since the stack monotonically increasing
        while (k--) res.pop_back();
        
        // remove all leading zeros
        int i = 0;
        while (i < res.size() && res[i] == '0') ++i;
        if (i == res.size()) return "0";
        return res.substr(i);
    }
};
