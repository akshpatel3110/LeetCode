    class Solution {
    public:
        int maximalRectangle(vector<vector<char>>& matrix) {
            if (matrix.empty() || matrix[0].empty())
                return 0;

            int m = matrix.size(), n = matrix[0].size(), res = 0;
            vector<vector<int>> heights(m, vector<int>(n));
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (matrix[i][j] == '1') {
                        if (i) heights[i][j] = 1 + heights[i - 1][j];
                        else heights[i][j] = 1;
                    }
                }
                res = max(res, largestRectangleArea(heights[i]));
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
