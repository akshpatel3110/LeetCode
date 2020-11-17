class Solution {
public:
    // Time: O(n)
    // Space: O(n)
    string frequencySort(string s) {
        vector<string> buckets(s.size() + 1);
        unordered_map<char, int> hash;
        for (char c : s) ++hash[c];
        for (auto [c, cnt] : hash)
            buckets[cnt].append(cnt, c);
        
        string res;
        for (int i = s.size(); i > 0; --i)
            if (!buckets[i].empty())
                res.append(buckets[i]);
        return res;
    }
};
