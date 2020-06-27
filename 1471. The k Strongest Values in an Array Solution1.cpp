class Solution {
public:
    // Time: O(n + klogn)
    // Space: O(n)
    vector<int> getStrongest(vector<int>& arr, int k) {
        nth_element(arr.begin(), arr.begin() + (arr.size() - 1) / 2, arr.end());
        int m = arr[(arr.size() -1) / 2];
        auto cmp = [&](int a, int b) { 
            return abs(a - m) == abs(b - m) ? a < b : abs(a - m) < abs(b - m); 
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(arr.begin(), arr.end(), cmp);
        vector<int> res;
        while (res.size() < k) {
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
};
