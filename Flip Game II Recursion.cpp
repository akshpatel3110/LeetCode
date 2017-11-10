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
        int n = s.size();
        
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == '+' && s[i + 1] == '+') {
                s[i] = s[i + 1] = '-';
                bool opponentWin = canWin(s);
                s[i] = s[i + 1] = '+';
                if (!opponentWin)
                    return true;
            }
        }
        
        return false;
    }
};
