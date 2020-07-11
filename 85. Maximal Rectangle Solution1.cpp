class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        
        int m = matrix.size(), n = matrix[0].size(), res = 0;
        vector<int> heights(n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '0') {
                    heights[j] = 0;
                } else {
                    ++heights[j];
                }
            }
            res = max(res, largestRectangleArea(heights));
        }
        return res;
    }
    
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
