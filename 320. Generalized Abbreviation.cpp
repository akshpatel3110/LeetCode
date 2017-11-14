/*
time O(2^n)

pos: points to the current character
cur: current string formed
count: how many letters are abbreviated in the current streak

At each step:
    Abbreviate the current letter
    Keep the current letter and summarize the abbreviation in the current streak

*/

class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        dfs(res, word, 0, "", 0);
        return res;
    }
    
    void dfs(vector<string>& res, const string& word, size_t pos, string cur, int count) {
        if (pos == word.size()) {
            if (count > 0)
                cur += to_string(count);
            res.push_back(cur);
            return;
        }
        
        // Abbreviation this letter
        dfs(res, word, pos + 1, cur, count + 1);
        
        // Keep this letter, summarize the abbreviation in the current streak
        if (count > 0)
            cur += to_string(count);
        cur += word[pos];

        dfs(res, word, pos + 1, cur, 0);
    }
};
