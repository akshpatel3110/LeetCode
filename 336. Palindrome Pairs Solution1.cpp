class Solution {
public:
    bool is_palin(const string & s) {
        for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
            if (s[i] != s[j])
                return false;
        }
        return true;
    }
    
    // Time: O(nL^2)
    // Space: O(n)
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> hash;
        for (int i = 0; i < words.size(); ++i) {
            auto w = words[i];
            reverse(w.begin(), w.end());
            hash[w] = i;
        }
        
        vector<vector<int>> res;
        // enumerate the longer or equal size string
        // equal size string will be counted twice, dedup in the second if
        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j <= words[i].size(); ++j) {
                auto left = words[i].substr(0, j), right = words[i].substr(j);
                if (is_palin(right) && hash.count(left) && hash[left] != i)
                    res.push_back({i, hash[left]});
                
                if (is_palin(left) && hash.count(right) && hash[right] != i &&
                    words[i].size() != words[hash[right]].size())
                    res.push_back({hash[right], i});
            }
        }
        return res;
    }
};
