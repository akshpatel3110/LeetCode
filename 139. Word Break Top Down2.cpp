class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.cbegin(), wordDict.cend());
        unordered_map<string, bool> memo;
        return wordBreak(s, wordSet, memo);
    }
    
    bool wordBreak(const string& s, const unordered_set<string>& wordSet, unordered_map<string, bool>& memo) {
        auto it = memo.find(s);
        if (it != memo.end()) 
            return it->second;
        
        if (wordSet.find(s) != wordSet.end()) 
            return memo[s] = true;
        
        for (int pos = 1; pos < s.size(); ++pos) {
            // Check whether right part is in word set
            const string right = s.substr(pos);
            if (wordSet.find(right) == wordSet.end())
                continue;
            
            // Check whether left part can be segmented
            const string left = s.substr(0, pos);           
            if (wordBreak(left, wordSet, memo))
                return memo[s] = true;
        }
        
        // No solution for s
        return memo[s] = false;
    }

};
