/*
happy number: 19 -> 82 > 68 -> 100 -> 1

Non-happy number: 200 -> 4 -> 16 -> 37 -> 58 -> 89 -> 145 -> 42 -> 20 -> 4
                  slow
                  fast
*/

class Solution {
public:
    int digitSquareSum(int n) {
        int sum = 0;
        int tmp;
        while (n) {
            tmp = n % 10;
            sum += tmp * tmp;
            n /= 10;
        }
        return sum;
    }
    
    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        do {
            slow = digitSquareSum(slow);
            fast = digitSquareSum(fast);
            fast = digitSquareSum(fast);
        } while (slow != fast);
        return slow == 1;
    }
};
