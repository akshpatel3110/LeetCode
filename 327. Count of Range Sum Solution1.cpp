class Solution {
public:
    using LL = long long;
    int dl;
    vector<int> tr;
    vector<LL> ds; // discretized sums
    
    int get(LL x) {
        return lower_bound(ds.begin(), ds.end(), x) - ds.begin() + 1; // number in tr starts from 1
    }
    
    int lowbit(int x) {
        return x & -x;
    }
    
    void add(int x, int v) {
        for (int i = x; i <= dl; i += lowbit(i))
            tr[i] += v;
    }
    
    int query(int x) {
        int res = 0;
        for (int i = x; i; i -= lowbit(i))
            res += tr[i];
        return res;
    }
    
    // Time: O(nlogn + nlogn) = O(nlogn)
    // Space: O(n)
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<LL> s(n + 1);
        ds.push_back(0); // we always have a prefix sum of 0
        for (int i = 1; i <= n; ++i) {
            s[i] = s[i - 1] + nums[i - 1];
            ds.push_back(s[i]);
            ds.push_back(s[i] - lower);
            ds.push_back(s[i] - upper - 1);
        }
        
        sort(ds.begin(), ds.end());
        ds.erase(unique(ds.begin(), ds.end()), ds.end());
        dl = ds.size();
        tr.resize(dl + 1);
        
        int res = 0;
        add(get(0), 1); // add entry of prefix sum 0
        for (int i = 1; i <= n; ++i) {
            res += query(get(s[i] - lower)) - query(get(s[i] - upper - 1));
            add(get(s[i]), 1);
        }
        return res;
    }
};
