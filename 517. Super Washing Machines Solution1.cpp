class Solution {
public:
    // Time: O(n)
    // Space: O(n)
    int findMinMoves(vector<int>& machines) {
        int n = machines.size();
        vector<int> sum(n + 1);
        for (int i = 0; i < n; ++i)
            sum[i + 1] = sum[i] + machines[i];

        if (sum[n] % n) return -1;

        int avg = sum[n] / n;
        int res = 0;
        for (int i = 0; i < n; ++i)
        {
            int l = i * avg - sum[i];
            int r = (n - i - 1) * avg - (sum[n] - sum[i] - machines[i]);

            if (l > 0 && r > 0)
                res = max(res, l + r);
            else
                res = max({res, abs(l), abs(r)});
        }
        return res;
    }
};
