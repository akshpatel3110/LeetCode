class Solution {
public:
    const int p = 1337;
    
    int qmi(int a, int k) {
        a %= p;
        int res = 1;
        while (k) {
            if (k & 1) res = res * a % p;
            a = a * a % p;
            k >>= 1;
        }
        return res;
    }
    
    // Time: O(n)
    // Space: O(n)
    int superPow(int a, vector<int>& b) {
        if (b.empty()) return 1;
        int t = b.back();
        b.pop_back();
        return qmi(superPow(a, b), 10) * qmi(a, t) % p; 
    }
};
