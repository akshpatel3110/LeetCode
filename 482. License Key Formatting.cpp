/*
Every (K + 1)th char from the back we have '-'

S = "2-4A0r7-4k", K = 3
    i

res
24-A0R-74k

*/

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string res;
        for (auto it = S.rbegin(); it < S.rend(); ++it) {
            if (*it != '-') {
                if (res.size() % (K + 1) == K)
                    res += '-';
                res += toupper(*it);
            }
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};
