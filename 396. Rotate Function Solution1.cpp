class Solution {
public:
    // Time: O(n)
    // Space: O(1)
    int maxRotateFunction(vector<int>& A) {
        using LL = long long;
        LL sum = 0;
        for (auto x : A) sum += x;
        LL cur = 0;
        int n = A.size();
        for (int i = 0; i < n; ++i) cur += i * A[i];
        LL res = cur;
        for (int i = n - 1; i >= 0; --i) {
            cur += sum - (LL)n * A[i];
            res = max(res, cur);
        }
        return res;
    }
};
