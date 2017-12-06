class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.cbegin(), wordDict.cend());
        unordered_map<string, vector<string>> memo;
        return wordBreak(s, wordSet, memo);
    }
private:
    
    const vector<string>& wordBreak(const string& s, const unordered_set<string>& wordSet, unordered_map<string, vector<string>>& memo) {
        if (memo.find(s) != memo.end())
            return memo[s];
        
        if (s.empty())
            return {};
        
        vector<string> res;
        if (wordSet.find(s) != wordSet.end()) 
            res.push_back(s);
        
        for (int pos = 1; pos < s.size(); ++pos) {
            // Check whether right part is in word set
            const string right = s.substr(pos);
            if (wordSet.find(right) == wordSet.end()) 
                continue;
            
            // Get break result for left part
            const string left = s.substr(0, pos);
            const vector<string>& leftRes = wordBreak(left, wordSet, memo);
            
            // Combine
            for (const string& lres: leftRes) {
                res.push_back(lres + " " + right);
            }
        }
        
        // remember and return
        memo[s].swap(res);
        return memo[s];
    }
    
};
