class Solution {
public:
    // Time: O(nlogn)
    // Space: O(n) for additional indexes
    vector<int> findRightInterval(vector<vector<int>>& q) {
        int n = q.size();
        for (int i = 0; i < n; ++i)
            q[i].push_back(i);
        
        sort(q.begin(), q.end());
        vector<int> res(n, -1);
        for (int i = 0; i < n; ++i) {
            int l = i + 1, r = n - 1;
            while (l < r) {
                int m = l + r >> 1;
                if (q[m][0] >= q[i][1])
                    r = m;
                else
                    l = m + 1;
            }
            if (q[r][0] >= q[i][1]) // use r here, because while loop might not be entered
                res[q[i][2]] = q[r][2];
        }

        
        return res;
    }
};
