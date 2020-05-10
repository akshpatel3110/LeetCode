class Solution {
public:
    // Time: O(n)
    // Space: O(k)
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;
        
        for (int i = 0; i < nums.size(); ++i) {
            // dq is in descending order (invariant)            
            while (!dq.empty() && nums[i] >= nums[dq.back()])
                dq.pop_back(); 
            
            // push the index of current element to the deque
            dq.push_back(i);
            
            // Remove elements out of window
            if (dq.front() == i - k)
                dq.pop_front();

            if (i >= k - 1)
                res.push_back(nums[dq.front()]);
        }
        return res;
    }
};
