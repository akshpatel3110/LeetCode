class Solution {
public:
    // Time: O(s + t)
    // Space: O(1)
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) 
            return false;
        
        vector<int> m(26);
        for (int i = 0; i < s.size(); ++i) 
            ++m[s[i] - 'a'];
        
        for (int i = 0; i < t.size(); ++i)
            if (--m[t[i] - 'a'] < 0) 
                return false;
            
        return true;        
    }
};
