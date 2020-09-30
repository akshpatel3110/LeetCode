class Solution {
public:
    // Time: O(k(m ^ 2 + n ^ 2))
    // Space: O(m + n)
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        vector<int> res(k, INT_MIN);
        for (int i = max(0, k - n); i <= min(k, m); ++i) {
            auto a = max_seq(nums1, i);
            auto b = max_seq(nums2, k - i);
            
            // merge
            vector<int> z;
            deque<int> x(a.begin(), a.end());
            deque<int> y(b.begin(), b.end());
            while (x.size() && y.size()) {
                if (x > y) {
                    z.push_back(x.front()); 
                    x.pop_front();
                } else {
                    z.push_back(y.front());
                    y.pop_front();
                }
            }
            
            while (x.size()) {
                z.push_back(x.front()); 
                x.pop_front();
            }
            
            while (y.size()) {
                z.push_back(y.front());
                y.pop_front();
            }
            
            res = max(res, z);
        }
        return res;
    }
    
    vector<int> max_seq(vector<int> & nums, int p) {
        vector<int> res(p);
        int n = nums.size();
        for (int i = 0, j = 0; i < nums.size(); ++i) {
            while (j && res[j - 1] < nums[i] && j + n - i > p)
                --j;
            
            if (j < p) 
                res[j++] = nums[i];
        }
        return res;
    }
};
