class Solution {
public:
    // Time: O(n)
    // Space: O(n)
    int trap(vector<int>& height) {
        int res = 0, n = height.size();
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            while (st.size() && height[st.top()] <= height[i]) {
                int t = st.top();
                st.pop();
                if (st.empty())
                    break;
                res += (i - st.top() - 1) *(min(height[st.top()], height[i]) - height[t]);
            }
            st.push(i);
        }
        return res;
    }
};
