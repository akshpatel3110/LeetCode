class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) {
        vector<int> pre(n);
        for (auto& e : dependencies) {
            e[0] -= 1;
            e[1] -= 1;
            pre[e[1]] |= 1 << e[0];
        }
        vector<int> dp(1 << n, INT_MAX);
        dp[0] = 0;
        for(int s = 0; s < (1 << n); ++s) {
            if (dp[s] == INT_MAX) continue;
            
            vector<int> avai;
            for (int i = 0; i < n; ++i) {
                if (((s >> i) & 1) == 1) continue;
                if ((s & pre[i]) != pre[i]) continue;
                avai.push_back(i);
            }
            int a = avai.size();
            function<void(int, int, int)> dfs = [&](int k, int start, int cur) {
                if (k == 0 || start >= a) {
                    dp[s | cur] = min(dp[s | cur], dp[s] + 1);
                    return;
                }
                for (int i = start; i < a && a - i >= k; ++i) {
                    dfs(k - 1, i + 1, cur + (1 << avai[i]));
                }
            };
            dfs(min(k, a), 0, 0);
        }
        return dp.back();        
    }
};
