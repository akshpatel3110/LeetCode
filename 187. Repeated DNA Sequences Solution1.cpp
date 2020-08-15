class Solution {
public:
    // Time: O(10n) = O(n)
    // Space: O(n)
    vector<string> findRepeatedDnaSequences(string s) {
        using ULL = unsigned long long;
        const int P = 100;
        unordered_map<string, int> m;
        vector<string> res;
        ULL h = 0;
        for (int i = 0; i + 10 - 1 < s.size(); ++i) {
            string t = s.substr(i, 10);
            
            if (m[t]++ == 1)
                res.push_back(move(t));
        }
        return res;
    }
};
