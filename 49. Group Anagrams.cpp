// n: sizeof(strs)
// l: average length of a string
// Time: O(nllogl)
// Space: since value is moved, should be O(number of unique keys) = O(nl)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> dic;
        for (auto & s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            dic[key].push_back(s);
        }
        
        vector<vector<string>> res;
        for (auto & kv : dic) {
            res.push_back(move(kv.second));
        }
        return res;
    }
};
