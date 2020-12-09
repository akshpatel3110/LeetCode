class Solution {
public:
    using LL = long long;
    int dl;
    vector<int> tr;
    vector<LL> dn; // discretized nums
    
    int get(LL x) {
        return lower_bound(dn.begin(), dn.end(), x) - dn.begin() + 1; // number in tr starts from 1
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
    
    // Time: O(nlogn)
    // Space: O(n)
    int reversePairs(vector<int>& nums) {
        // 1. discretize nums[i] and 2 * nums[i]
        int n = nums.size();
        dn.reserve(2 * n);
        for (int i = 0; i < n; ++i) {
            dn.push_back(nums[i]);
            dn.push_back(2ll * nums[i]);
        }
        sort(dn.begin(), dn.end());
        dn.erase(unique(dn.begin(), dn.end()), dn.end());
        dl = dn.size();
        tr.resize(dl + 1);
        
        // 2. count
        int res = 0;
        for (int i = n - 1; i >= 0; --i) {
            res += query(get(nums[i]) - 1);
            add(get(2ll * nums[i]), 1);
        }
        return res;
    }
};
