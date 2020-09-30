class Solution {
public:
    // Time: O(n ^ 2)
    // Space: O(n)
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> masks(n);
        for (int i = 0; i < n; ++i) {
            for (auto c : words[i])
                masks[i] |= 1 << (c - 'a');
        }
        
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if ((masks[i] & masks[j]) == 0) {
                    res = max(res, (int)(words[i].size() * words[j].size()));
                }
            }
        }
        return res;
    }
};
