class Solution {
public:
    struct A {
        int a, b, i; // i is index in nums1
        
        A(int a_, int b_, int i_) : a(a_), b(b_), i(i_) {}
        bool operator < (const A & rhs) const {
            return a + b > rhs.a + rhs.b; // min heap
        }
    };
    
    // Time: O(klogmin(k, n))
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        vector<vector<int>> res;
        if (m == 0 || n == 0) return res;
        
        priority_queue<A> heap;
        
        for (int j = 0; j < min(k, n); ++j)
            heap.push(A(nums1[0], nums2[j], 0));
        
        while (k-- && heap.size()) {
            auto t = heap.top();
            heap.pop();
            res.push_back({t.a, t.b});
            if (t.i < m - 1)
                heap.push(A(nums1[t.i + 1], t.b, t.i + 1));
        }
        return res;
    }
};
