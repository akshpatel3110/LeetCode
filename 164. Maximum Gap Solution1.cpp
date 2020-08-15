class Solution {
public:
    struct bucket {
        int Min = INT_MAX;
        int Max = INT_MIN;
        bool empty = true;
    };
    
    // Time: O(n)
    // Space: O(n)
    int maximumGap(vector<int>& nums) {
        int n = nums.size(), Min = INT_MAX, Max = INT_MIN;
        for (int x : nums) {
            Min = min(Min, x);
            Max = max(Max, x);
        }
        if (n < 2)
            return 0;
        
        vector<bucket> b(n - 1);
        int bucket_len = (Max - Min + n - 2) / (n - 1);
        for (int x : nums) {
            if (x == Min) continue;
            int k = (x - Min - 1) / bucket_len;
            b[k].empty = false;
            b[k].Min = min(b[k].Min, x);
            b[k].Max = max(b[k].Max, x);
        }
        
        int res = 0;
        for (int i = 0, pre = Min; i < n - 1; ++i) {
            if (!b[i].empty) {
                res = max(res, b[i].Min - pre);
                pre = b[i].Max;
            }
        }
        return res;
    }
};
