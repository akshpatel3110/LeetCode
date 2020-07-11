class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_set<string> st;
        st.insert("0 0");
        int x = 0, y = 0;
        for (auto c : path) {
            if (c == 'N') --x;
            else if (c == 'S') ++x;
            else if (c == 'W') --y;
            else ++y;
            string s = to_string(x) + ' ' + to_string(y);
            if (st.count(s)) return true;
            st.insert(s);
        }

        return false;
    }
};
