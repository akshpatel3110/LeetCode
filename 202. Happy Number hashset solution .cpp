class Solution {
public:
    int digitSquareSum(int n) {
        int sum = 0, tmp;
        while (n) {
            tmp = n % 10;
            sum += tmp * tmp;
            n /= 10;
        }
    return sum;
}
    
    bool isHappy(int n) {
        unordered_set<int> s;
        s.insert(1);
        while (s.find(n) == s.end()) {
            s.insert(n);
            n = digitSquareSum(n);
        }
        return n == 1;
        
    }
};
