/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l = 1, r = n;
        while (l < r) {
            int m = l + (long long)r >> 1;
            int t = guess(m);
            if (t == 0) return m;
            if (t < 0) r = m;
            else l = m + 1;
        }
        return l;
    }
};
