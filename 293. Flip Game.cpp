/*
++++
   i

res
--++
+--+
++--

*/

class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> res;
        int n = s.size();
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == '+' && s[i + 1] == '+') {
                s[i] = s[i + 1] = '-';
                res.push_back(s);
                s[i] = s[i + 1] = '+';
            }
        }
        return res;
    }
};
