class Solution {
public:
    // Time: O(Catalan numbers)
    vector<int> diffWaysToCompute(string s) {
        vector<string> tokens;
        for (int i = 0; i < s.size(); ++i) {
            if (isdigit(s[i])) {
                int j = i;
                while (j < s.size() && isdigit(s[j]))
                    ++j;
                
                tokens.push_back(s.substr(i, j - i));
                i = j - 1;
            } else {
                // '+' '-' '*'
                tokens.push_back(s.substr(i, 1)); // cannot use to_string
            }
        }
        
        int n = (tokens.size() + 1) / 2; // count of numbers
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>()));
        for (int i = 0; i < n; ++i) 
            dp[i][i].push_back(stoi(tokens[i * 2]));
        
        for (int len = 1; len <= n; ++len) {
            for (int i = 0; i + len - 1 <= n - 1; ++i) {
                int j = i + len - 1;
                for (int k = i; k < j; ++k) {
                    auto & left = dp[i][k];
                    auto & right = dp[k + 1][j];
                    auto op = tokens[k * 2 + 1];
                    for (auto a : left) {
                        for (auto b : right) {
                            int c;
                            if (op == "+") c = a + b;
                            else if (op == "-") c = a - b;
                            else c = a * b;
                            dp[i][j].push_back(c);
                        }
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
};
