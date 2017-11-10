/*
Solution 1:
Recursion
T(N) = (N - 1) * T(N - 2) = (N - 1) * (N - 3) * T(N - 4) = (N - 1)!!

canWin("++++++") = !canWin("--++++") || !canWin("+--+++") || !canWin("++--++") + || !canWin("+++--+") || !canWin("++++--")
               
canWin("--++++") = !canWin("----++") || !canWin("--+--+") || !canWin("--++--")
canWin("++++--") = !canWin("--++--") || !canWin("+--+--") || !canWin("++----")


Solution 2:
Recursion + memoization



*/

class Solution {
public:
    bool canWin(string& s) {
        unordered_map<string, bool> dic;
        int n = s.size();
        return helper(s, dic, n);
    }
    
    bool helper(string& s, unordered_map<string, bool>& dic, int n) {
        auto it = dic.find(s);
        if (it != dic.end())
            return it->second;
        
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == '+' && s[i + 1] == '+') {
                s[i] = s[i + 1] = '-';
                bool opponentWin = helper(s, dic, n);
                s[i] = s[i + 1] = '+';
                if (!opponentWin) {
                    dic[s] = true;
                    return true;
                }
            }
        }
        
        dic[s] = false;
        return false;
    }
};
