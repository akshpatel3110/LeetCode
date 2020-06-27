class Solution {
public:
    // Time: O(n)
    // Space: O(n)
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> cnt;
        unordered_set<string> s;
        vector<string> res;
        for (const auto & name : names) {
            string suffix;
            int num = 0;
            if (cnt.count(name))
                num = cnt[name];
            
            while (s.count(name + suffix)) {
                ++num;
                suffix = "(" + to_string(num) + ")";
            }
            
            cnt[name] = num;
            s.insert(name + suffix);
            res.push_back(name + suffix);
        }
        return res;
    }
};
