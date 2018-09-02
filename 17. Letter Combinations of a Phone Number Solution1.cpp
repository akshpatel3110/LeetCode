class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) 
            return {};
        
        unordered_map<char, string> dic = {
            {'2', "abc"}, {'3', "def"},
            {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"},
            {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };
        
        vector<string> res;
        string cur;
        dfs(digits, dic, res, cur, 0);
        return res;
    }
    
private:
    void dfs(const string & digits,
             const unordered_map<char, string> & dic,
             vector<string> & res,
             string & cur,
             int idx) {
        if (idx == digits.size()) {
            res.push_back(cur);
            return;
        }
        
        for (const char c : dic.at(digits.at(idx))) {
            cur.push_back(c);
            dfs(digits, dic, res, cur, idx + 1);
            cur.pop_back();
        }
    }
};
