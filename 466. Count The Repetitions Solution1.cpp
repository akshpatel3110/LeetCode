class Solution {
public:
    // Time: O(len(s1) * len(s2))
    // Space: hash in O(len(s2)), s2_chars in O(n1)
    // in total: P(n1 + len(s2))
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        unordered_map<int, int> hash; // s2 index to ith s1
        vector<int> s2_chars; // number of chars matched in s2 for each s1
        for (int i = 0, k = 0; i < n1; ++i) {
            for (int j = 0; j < s1.size(); ++j)
                if (s1[j] == s2[k % s2.size()])
                    ++k;
            
            s2_chars.push_back(k);
            if (hash.count(k % s2.size())) {
                // calculate s2 chars matched in the loops
                int loop_s1_cnt = i - hash[k % s2.size()];
                int loop_s2_chars = k - s2_chars[hash[k % s2.size()]];
                int loops = (n1 - i - 1) / loop_s1_cnt;
                int matched_s2_chars = loops * loop_s2_chars;
                
                // add the remaining matched s2 chars
                int remaining_s1_cnt = (n1 - i - 1) % loop_s1_cnt;
                while (remaining_s1_cnt--) {
                    for (int j = 0; j < s1.size(); ++j)
                        if (s1[j] == s2[k % s2.size()])
                            ++k;
                    }
                matched_s2_chars += k;
                return (matched_s2_chars) / s2.size() / n2;
            }
            hash[k % s2.size()] = i;
        }
        if (s2_chars.empty()) return 0;
        return s2_chars.back() / s2.size() / n2;
    }
};
