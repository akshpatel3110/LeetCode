class Solution {
public:
    // Time: O(n)
    // Space: O(n)
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        if (n == 0) return 0;
        vector<int> D(n - 1);
        for (int i = 0; i < n - 1; ++i)
            D[i] = A[i + 1] - A[i];
        
        int res = 0;
        for (int i = 0; i < n - 1;) {
            int j = i;
            while (j < n - 1 && D[j] == D[i])
                ++j;
            
            int len = j - i;
            res += len * (len - 1) / 2;
            i = j;
        }
        return res;
    }
};
