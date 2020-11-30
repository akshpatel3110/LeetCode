class Solution {
public:
    int n;
    int side_len;
    vector<bool> used;
    
    bool dfs(int u, int cur_len, int cnt, const vector<int> & nums) {
        if (cnt == 3) return true;
        if (cur_len == side_len) return dfs(0, 0, cnt + 1, nums);
        for (int i = u; i < nums.size(); ++i) {
            if (used[i]) continue;
            if (cur_len + nums[i] <= side_len) {
                used[i] = true;
                if (dfs(i + 1, cur_len + nums[i], cnt, nums)) return true;
                used[i] = false;
            }
            if (!cur_len || cur_len + nums[i] == side_len) return false;
            while (i + 1 < nums.size() && nums[i + 1] == nums[i])
                ++i;
        }
        return false;
    }
    
    // optimization:
    // 1. enumerate from longer sticks to shorter sticks
    // 2. enumerate with an order: combination
    // 3. If we fail to put current stick, skip all subsequent sticks with same length
    // 4. If we fail to put the first or last stick of a side, no need to try other sticks
    bool makesquare(vector<int>& nums) {
        n = nums.size();
        if (n == 0) return false;
        used.resize(n);
        int total = 0;
        for (auto x : nums) total += x;
        if (total % 4) return false;
        side_len = total / 4;
        sort(nums.begin(), nums.end(), greater<int>());
        return dfs(0, 0, 0, nums);
    }
};
