/*
Solution 1: regex
!regex_search(s, regex("A.*A|LLL"))

Solution 2:
A number of A's encountered
L number of continuous L encountered

*/

class Solution {
public:
    bool checkRecord(string s) {
        int A = 0, L = 0;
        for (const char c: s) {
            if (c == 'A') {
                ++A;
                L = 0;
            } else if (c == 'L') {
                ++L;
            } else {
                L = 0;
            }
            
            if (A > 1 || L > 2)
                return false;
        }
        
        return true;
    }
};
