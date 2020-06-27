class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for (auto num : arr)
            ++mp[num];
        
        vector<int> cnt;
        for (auto & p : mp)
            cnt.push_back(p.second);
        sort(cnt.begin(), cnt.end());
        
        int res = cnt.size();
        for (auto c : cnt) {
            if (k >= c) {
                k -= c;
                --res;
            } else {
                break;
            }
        }
        return res;
    }
};
