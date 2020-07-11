class Solution {
public:
    // Time: O(n)
    // Space: O(n)
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(-1);
        int n = heights.size(), res = 0;
        // push -1 at the end so that all elements will be popped out and calculated
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            while (st.size() && heights[i] < heights[st.top()]) {
                int cur = st.top();
                st.pop();
                if (st.empty())
                    res = max(res, heights[cur] * i); // i - (-1) - 1
                else
                    res = max(res, heights[cur] * (i - st.top() - 1));
            }
            st.push(i);
        }
        return res;
    }
};
