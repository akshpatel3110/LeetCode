class Solution {
public:
    // Time: O(n)
    // Space: O(n)
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n, false);
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue;
            int cnt = 0, j = i;
            while (!visited[j]) {
                ++cnt;
                visited[j] = true;
                j = nums[j];
            }
            res = max(res, cnt);
        }
        return res;
    }
};
