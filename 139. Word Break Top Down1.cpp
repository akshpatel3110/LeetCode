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
            const string left = s.substr(0, pos);
            const string right = s.substr(pos);
            // Find solution for s
            if (wordSet.find(right) != wordSet.end() && wordBreak(left, wordSet))
                return true;
        }
        
        // No solution for s
        return false;
    }

};
