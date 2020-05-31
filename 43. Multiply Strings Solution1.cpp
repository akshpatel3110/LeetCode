class Solution {
public:
    // Time: O(mn)
    // Space: O(m + n)
    string multiply(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        vector<int> product(m + n);
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                product[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
                product[i + j] += product[i + j + 1] / 10;
                product[i + j + 1] %= 10;
            }
        }
        
        int k = 0;
        while (k < m + n && product[k] == 0)
            ++k;
        
        string res;
        for (int i = k; i < m + n; ++i)
            res += product[i] + '0';
        return res.empty() ? "0" : res;
    }
};
