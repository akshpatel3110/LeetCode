class Solution {
public:
    vector<string> wordBreak(string s, vector<string> & word_dict) {
        unordered_set<string> word_set(word_dict.cbegin(), word_dict.cend());
        unordered_map<string, vector<string>> memo;
        return word_break(s, word_set, memo);
    }
private:
    
    const vector<string>& word_break(const string & s, const unordered_set<string> & word_set, unordered_map<string, vector<string>> & memo) {
        auto p = memo.emplace(s, vector<string>());
        vector<string> & res = p.first->second;
        if (!p.second) // emplace failed, already in memo
            return res;
        
        // insertion took place
        if (s.empty())
            return {};
        
        // in_dic
        if (word_set.find(s) != word_set.end()) 
            res.push_back(s);
        
        // break and combine
        for (int pos = 1; pos < s.size(); ++pos) {
            // Check whether right part is in word set
            const string right = s.substr(pos);
            if (word_set.find(right) == word_set.end()) 
                continue;
            
            // Get break result for left part
            const string left = s.substr(0, pos);
            const vector<string> & left_res = word_break(left, word_set, memo);
            
            for (const string & lres: left_res) {
                res.push_back(lres + " " + right);
            }
        }
        
        return res;
    }
    
};
