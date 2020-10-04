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
    // Space: O(1)
    int superPow(int a, vector<int>& b) {
        int res = 1;
        for (int i = 0; i < b.size(); ++i) {
            res = qmi(res, 10) * qmi(a, b[i]) % p;
        }
        return res;
    }
};
