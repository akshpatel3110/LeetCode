
using LL = long long;

class Solution {
public:
    vector<string> res;
    string path;
    
    // maintain algebraic structure: a + b * c
    vector<string> addOperators(string num, int target) {
        int n = num.size();
        // path is at most 2 * n - 1, but n could be 0, yeah...
        path.resize(2 * n); 
        dfs(num, 0, 0, 0, 1, target);
        return res;
    }
    
    // u is for num, k is for path
    // Time: O(4 ^ n)
    // Space: O(n)
    void dfs(const string & num, int u, int k, LL a, LL b, LL target) {
        if (u == num.size()) {
            if (a == target)
                res.push_back(path.substr(0, k - 1)); // ignore the last '+'
            return;
        }
        
        // enumerate what is the next number and op
        LL c = 0;
        for (int i = u; i < num.size(); ++i) {
            c = c * 10 + num[i] - '0';
            path[k++] = num[i];
            
            // enumerate possible ops
            // the last op will be '+' so that value is stored in a to simplify code 
            path[k] = '+'; 
            dfs(num, i + 1, k + 1, a + b * c, 1, target);
            
            if (i + 1 < num.size()) {
                path[k] = '-';
                dfs(num, i + 1, k + 1, a + b * c, -1, target);
                
                path[k] = '*';
                dfs(num, i + 1, k + 1, a, b * c, target);
            }
            
            // we cannot have numbers like "023"
            if (num[u] == '0')
                break;
        }
    }
};
