class Solution {
public:
    // Time: O(nlogk)
    // Space: O(n + k)
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        using PII = pair<int, int>;
        vector<int> res(n);
        res[0] = 1;
        priority_queue<PII, vector<PII>, greater<PII>> heap;
        for (int p : primes) 
            heap.push({p, 0}); // ugly number and its index in res
        
        for (int i = 1; i < n; ++i) {
            int min_ugly = heap.top().first;
            res[i] = min_ugly;
            while (heap.top().first == min_ugly) {
                auto t = heap.top(); heap.pop();
                int idx = t.second, p = t.first / res[idx];
                heap.push({p * res[idx + 1], idx + 1});
            }
        }
        return res.back();
    }
};
