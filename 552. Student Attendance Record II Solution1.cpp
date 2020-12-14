class Solution {
public:    
    // Time: O(n)
    // Space: O(n)
    // f[i][j][k]: number of records for i attendance records, j absents and ends with k lates
    int checkRecord(int n) {
        const int mod = 1e9 + 7, N = 100010;
        int f[N][2][3] = {0};
        f[0][0][0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < 3; ++k) {
                    if (j == 0) f[i + 1][j + 1][0] = (f[i + 1][j + 1][0] + f[i][j][k]) % mod;
                    if (k + 1 <= 2) f[i + 1][j][k + 1] = (f[i + 1][j][k + 1] + f[i][j][k]) % mod;
                    f[i + 1][j][0] = (f[i + 1][j][0] + f[i][j][k]) % mod;
                }
            }
        }
        
        int res = 0;
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 3; ++k) {
                res = (res + f[n][j][k]) % mod;
            }
        }
        return res;
    }
};
