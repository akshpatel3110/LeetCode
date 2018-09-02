class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) 
            return {};
        
        vector<string> dic = {
            {" "},
            {""},
            {"abc"},
            {"def"},
            {"ghi"},
            {"jkl"},
            {"mno"},
            {"pqrs"},
            {"tuv"},
            {"wxyz"}
        };
        
        vector<string> res;
        string cur;
        dfs(digits, dic, res, cur, 0);
        return res;
    }
    
private:
    void dfs(const string & digits,
             const vector<string> & dic,
             vector<string> & res,
             string & cur,
             int idx) {
        if (idx == digits.size()) {
            res.push_back(cur);
            return;
        }
        
        for (const char c : dic[digits[idx] - '0']) {
            cur.push_back(c);
            dfs(digits, dic, res, cur, idx + 1);
            cur.pop_back();
        }
    }
};
