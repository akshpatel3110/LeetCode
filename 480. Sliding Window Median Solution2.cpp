class Solution {
public:
    // size: small == large if k is even
    //       small == large + 1 if k is odd
    int k;
    multiset<int> small, large; 
    
    double get_median() {
        if (k % 2) return *small.rbegin();
        return ((double)*small.rbegin() + *large.begin()) / 2;
    }
    
    // Time: O(nlogk)
    // Space: O(k)
    vector<double> medianSlidingWindow(vector<int>& nums, int _k) {
        k = _k;
        // initialize small and large
        for (int i = 0; i < k; ++i)
            small.insert(nums[i]);
        
        for (int i = 0; i < k / 2; ++i) {
            large.insert(*small.rbegin());
            small.erase(small.find(*small.rbegin())); // cannot erase reverse iterator
        }
        
        vector<double> res;
        res.push_back(get_median());
        for (int i = k; i < nums.size(); ++i) {
            int a = nums[i], b = nums[i - k], diff = 0; // diff in "additional" diff
            if (a <= *small.rbegin()) {
                small.insert(a); 
                ++diff;
            } else {
                large.insert(a);
                --diff;
            }

            if (b <= *small.rbegin()) {
                small.erase(small.find(b));
                --diff;
            } else {
                large.erase(large.find(b));
                ++diff;
            }

            // one insertion and one deletion happened, 
            // which might cause an additional size diff of -2, 0 or 2 between small and large
            if (diff == 2) {
                large.insert(*small.rbegin());
                small.erase(small.find(*small.rbegin()));
            } else if (diff == -2) {
                small.insert(*large.begin());
                large.erase(large.begin());
            }
            // do nothing if additional diff is 0;

            res.push_back(get_median());
        }
        return res;
    }
};
