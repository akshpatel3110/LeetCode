class Solution {
public:
    // Time: O(n ^ 2)
    // Space: O(n)
    bool wordBreak(string s, vector<string>& wordDict) {
        using ULL = unsigned long long;
        unordered_set<ULL> hash;
        const int P = 131;
        for (auto & word : wordDict) {
            ULL h = 0;
            for (auto c : word)
                h = h * P + c;
            
            hash.insert(h);
        }
        
        int n = s.size();
        vector<bool> dp(n + 1);
        dp[n] = true;
        
        // here the index of s and dp matches except dp has one more entry
        // at the end
        for (int i = n - 1; i >= 0; --i) {
            ULL h = 0;
            for (int j = i; j < n; ++j) { // the i + 1 th char's index is i
                h = h * P + s[j];
                if (hash.count(h) && dp[j + 1]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
        
    }
};
