class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) {
        vector<int> pre(n);
        for(auto& e : dependencies){
            e[0] -= 1;
            e[1] -= 1;
            pre[e[1]] |= 1 << e[0];
        }
        vector<int> dp(1 << n, n);
        dp[0] = 0;
        for(int s = 0; s < (1 << n); s += 1) {
            int avai = 0;
            for (int i = 0; i < n; i += 1) 
                if ((s & pre[i]) == pre[i])
                    avai |= 1 << i;
            
            avai &= ~s;
            for(int i = avai; i; i = (i - 1) & avai) 
                if(__builtin_popcount(i) <= k) {
                dp[s | i] = min(dp[s | i], dp[s] + 1);
            }
        }
        return dp.back();
    }
};
