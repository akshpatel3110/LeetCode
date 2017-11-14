/*
All counts of characters are even
All counts of characters are even except one
*/

class Solution {
public:
    bool canPermutePalindrome(string s) {
        bitset<256> b;
        for (const char c : s)
            b.flip(c);
        
        return b.count() <= 1;
    }
};
