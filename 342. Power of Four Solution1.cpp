class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num <= 0) return false;
        int t = sqrt(num);
        return t * t == num && ((1 << 30) % num) == 0;        
    }
};
