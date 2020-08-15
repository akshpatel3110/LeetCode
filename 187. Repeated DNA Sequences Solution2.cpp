class Solution {
public:
    // sliding window, rolling hash
    // Time: O(n)
    // Space: O(n)
    vector<string> findRepeatedDnaSequences(string s) {
        using ULL = unsigned long long;
        const int P = 31;
        unordered_map<ULL, int> m;
        vector<string> res;
        ULL h = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (i >= 10)
                h -= s[i - 10] * (ULL)pow(P, 9);
            
            h = h * P  + s[i];
            if (i < 9)
                continue;
            
            if (m[h]++ == 1)
                res.push_back(s.substr(i - 9, 10));
        }
        return res;
    }
};
