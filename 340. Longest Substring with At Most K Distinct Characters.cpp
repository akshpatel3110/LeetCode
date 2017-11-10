/*
Naive
o(n ^ 2) time
o(n) space
XXXXXXXXX
 s  
       e


Two pointers
o(n) time
o(n) space

Invariant: A window of at most K distinct characters before the start of each iteration
Fix e, move s

maxlen = 3

eceba   k = 2
   s
     e

dic
b : 1
a : 1

*/

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string str, int k) {
        int s = 0, e = 0, maxlen = 0;
        unordered_map<char, int> dic;
        while (e < str.size()) {
            char c = str[e];
            if (dic.find(c) != dic.end()) {
                ++dic[c];
            } else {
                dic[c] = 1;
            }
            
            while (dic.size() > k) {
                c = str[s];
                if (--dic[c] == 0) {
                    dic.erase(c);
                }
                ++s;
            }
            maxlen = max(maxlen, e - s + 1);
            ++e;
            
        }
        
        return maxlen;
        
    }
};
