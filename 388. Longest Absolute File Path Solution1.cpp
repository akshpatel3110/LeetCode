class Solution {
public:
    
    // Time: O(n)
    // Space: O(level)
    // Use a stack to maintain the current dfs path
    // Or we can use a hashmap to maintain level length but it is really just an optimization.
    int lengthLongestPath(string input) {
        stack<int> st;
        int res = 0;
        for (int i = 0, path_len = 0; i < input.size(); ++i) {
            // count number of tabs
            int j = i;
            while (i < input.size() && input[i] == '\t') ++i;
            int num_tabs = i - j;
            while (st.size() > num_tabs) {
                path_len -= st.top();
                st.pop();
            }
            
            // take out current word
            j = i;
            while (i < input.size() && input[i] != '\n') ++i;
            int word_len = i - j;
            string t = input.substr(j, word_len);
            st.push(word_len), path_len += word_len;
            
            // only update if current word is a file
            if (t.find('.') != -1)
                res = max(res, path_len + (int)st.size() - 1); // (int)st.size() - 1 is the numebr of tabs
        }
        return res;
    }
};
