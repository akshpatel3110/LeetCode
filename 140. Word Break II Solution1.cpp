class Solution {
public:
    int n;
    vector<int> dp;
    vector<string> res;
    string path;
    unordered_set<string> hash;
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        dp.resize(n + 1);
        for (auto & word : wordDict)
            hash.insert(word);
        
        dp[n] = true;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (dp[j + 1] && hash.count(s.substr(i, j - i + 1))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        dfs(s, 0);
        return res;
    }
    
    void dfs(const string & s, int u) {
        if (u == n) {
            path.pop_back();
            res.push_back(path);
            path += ' ';
        } else {
            for (int i = u; i < n; ++i) {
                if (dp[i + 1]) {
                    auto word = s.substr(u, i - u + 1);
                    if (hash.count(word)) {
                        path += word + ' ';
                        dfs(s, i + 1);
                        for (int i = 0; i < word.size() + 1; ++i)
                            path.pop_back();
                    }
                }
            }
        }
    }
};
