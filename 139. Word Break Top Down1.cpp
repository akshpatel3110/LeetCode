/*
brute force dfs

*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.cbegin(), wordDict.cend());
        return wordBreak(s, wordSet);
    }
    
    bool wordBreak(const string& s, const unordered_set<string>& wordSet) {
        if (wordSet.find(s) != wordSet.end()) 
            return true;
        
        for (int pos = 1; pos < s.size(); ++pos) {
            // Check whether right part is in word set
            const string right = s.substr(pos);
            if (wordSet.find(right) == wordSet.end())
                continue;
            
            // Check whether left part can be segmented
            const string left = s.substr(0, pos);           
            if (wordBreak(left, wordSet))
                return true;
        }
        
        // No solution for s
        return false;
    }

};
