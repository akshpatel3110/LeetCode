class Solution {
public:
    // Time: O(n)
    // Space: O(n)
    string simplifyPath(string path) {
        string res, token;
        vector<string> st;
        stringstream ss(path);
        while (getline(ss, token, '/')) {
            if (token == "..") {
                if (st.size()) st.pop_back();
            } else if (token != "." && token != "") {
                st.push_back(token);
            }
        }
        
        for (auto & token : st) {
            res += '/' + token;
        }
        
        if (res.empty()) res = "/";
        return res;
    }
};
