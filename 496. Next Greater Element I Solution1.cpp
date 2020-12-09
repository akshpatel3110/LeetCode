class Solution {
public:
    // monotonic stack
    // Time: O(n)
    // Space: O(n)
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        vector<int> p(nums2.size());
        for (int i = nums2.size() - 1; i >= 0; --i) {
            while (st.size() && nums2[i] >= st.top())
                st.pop();
            
            if (st.empty()) p[i] = -1;
            else p[i] = st.top();
            st.push(nums2[i]);
        }
        
        unordered_map<int, int> pos;
        for (int i = 0; i < nums2.size(); ++i)
            pos[nums2[i]] = i;
        
        vector<int> res;
        for (auto x : nums1)
            res.push_back(p[pos[x]]);
        return res;
    }
};
