class Solution {
public:
    // monotonic stack
    // Time: O(n)
    // Space: O(n)
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.end(), nums.begin(), nums.end());
        stack<int> st;
        vector<int> res(n);
        for (int i = 2 * n - 1; i >= 0; --i) {
            while (st.size() && nums[i] >= st.top()) st.pop();
            if (i < n) {
                if (st.empty()) res[i] = -1;
                else res[i] = st.top();
            }
            st.push(nums[i]);
        }
        return res;
    }
};
