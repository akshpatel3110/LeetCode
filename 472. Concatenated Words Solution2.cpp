class Solution {
public:
    unordered_set<string> hash;
    
    bool check(const string & word) {
        int n = word.size();
        vector<int> dp(n + 1, INT_MIN); // additional dp[0]
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            if (dp[i] == INT_MIN) continue;
            for (int j = n; j >= i + 1; --j) {
                // j - i < n to make sure dp[n] consists of at least two words
                if (hash.count(word.substr(i, j - i))) {
                    dp[j] = max(dp[j], dp[i] + 1);
                    if (dp[n] > 1) {
                        return true;
                    }
                }
            }
        }        
        return false;
    }
    
    // forward update is faster since we don't have to calculate from dp[0] tp dp[n] one by one
    // the for loop might break early once we find dp[n] is true
    // Time: O(n ^ 3 * m)
    // Space: O(nm)
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        for (auto & word : words)
            hash.insert(word);
        
        vector<string> res;
        for (const auto & word : words) {
            if (check(word)) 
                res.push_back(word);
        }
        return res;        
    }
};
