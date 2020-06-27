class Solution {
public:
    // Time: O(n)
    // Space: O(n)
    int longestValidParentheses(string s) {
        int res = 0;
        stack<int> st;
        for (int i = 0, start = -1; i < s.size(); ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                if (st.size()) {
                    st.pop();
                    if (st.size()) {
                        res = max(res, i - st.top());
                    } else {
                        res = max(res, i - start);
                    }
                } else {
                    start = i;
                }
            }
        }
        return res;
    }
};
