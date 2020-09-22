class NumArray {
public:
    vector<int> nums, tr;
    int n;
    
    int lowbit(int x) {
        return x & (-x);
    }
    
    int query(int x) {
        int res = 0;
        for (int i = x; i; i -= lowbit(i))
            res += tr[i];
        return res;
    }
    
    void add(int x, int v) {
        for (int i = x; i <= n; i += lowbit(i))
            tr[i] += v;
    }
    
    NumArray(vector<int>& _nums) {
        nums = _nums;
        n = nums.size();
        tr.resize(n + 1);    
        for (int i = 0; i < n; ++i)
            add(i + 1, nums[i]);
    }
    
    void update(int i, int val) {
        add(i + 1, val - nums[i]);
        nums[i] = val;
    }
    
    int sumRange(int i, int j) {
        ++i, ++j;
        return query(j) - query(i - 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
