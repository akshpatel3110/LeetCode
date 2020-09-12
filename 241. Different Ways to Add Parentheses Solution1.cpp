class Solution {
public:
    vector<string> tokens;
    
    // Time: O(Catalan numbers)
    vector<int> diffWaysToCompute(string s) {
        for (int i = 0; i < s.size(); ++i) {
            if (isdigit(s[i])) {
                int j = i, x = 0;
                while (j < s.size() && isdigit(s[j]))
                    ++j;
                
                tokens.push_back(s.substr(i, j - i));
                i = j - 1;
            } else {
                // '+' '-' '*'
                tokens.push_back(s.substr(i, 1)); // cannot use to_string
            }
        }
        return dfs(0, tokens.size() - 1);
    }
    
    vector<int> dfs(int l, int r) {
        if (l == r)
            return {stoi(tokens[l])};
        
        vector<int> res;
        // i is all positions for "+", "-", "*"
        for (int i = l + 1; i < r; i += 2) {
            auto left = dfs(l, i - 1);
            auto right = dfs(i + 1, r);
            for (auto a : left) {
                for (auto b : right) {
                    int c;
                    if (tokens[i] == "+") {
                        c = a + b;
                    } else if (tokens[i] == "-") {
                        c = a - b;
                    } else {
                        c = a * b;
                    }
                    res.push_back(c);
                }
            }
        }
        return res;
    }
};
