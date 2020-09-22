class Solution {
public:
    // Time: O(n)
    // Space: O(n)
    bool wordPattern(string pattern, string s) {        
        vector<string> words;
        istringstream ss(s);
        string word;
        while (ss >> word)
            words.push_back(word);

        if (pattern.size() != words.size())
            return false;
        
        unordered_map<char, string> pw;
        unordered_map<string, char> wp;
        for (int i = 0; i < pattern.size(); ++i) {
            auto p = pattern[i];
            auto & w = words[i];
            if (pw.count(p) && pw[p] != w)
                return false;
            
            pw[p] = w;
            
            if (wp.count(w) && wp[w] != p)
                return false;
            
            wp[w] = p;
        }
        return true;
    }
};
