class Solution {
public:
    // Time: O(n)
    // Space: O(token size)
    string simplifyPath(string path) {
        string res, token;
        if (path.back() != '/')
            path += '/';
        
        for (auto c : path) {
            if (c != '/') {
                token += c;
            } else {
                if (token == "..") {
                    while (res.size() && res.back() != '/')
                        res.pop_back();
                    
                    if (res.size())
                        res.pop_back();
                } else if (token != "." && token != "") {
                    res += '/' + token;
                }
                token.clear();
            }
        }
        
        if (res.empty())
            res = "/";
        return res;
    }
};
