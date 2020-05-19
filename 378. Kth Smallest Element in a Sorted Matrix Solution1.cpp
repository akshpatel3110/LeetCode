class Solution {
public:
    // Time: O((m + n)logd) where d is max(matrix) - min(matrix)
    // Space: O(1)
    int numbers_less_than_or_equal(const vector<vector<int>> & matrix, int m) {
        int count = 0, i = 0, j = matrix[0].size() - 1;
        while (i < matrix.size() && j >= 0) {
            if (matrix[i][j] <= m) {
                count += j + 1;
                ++i;
            } else {
                --j;
            }
        }
        return count;
        
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if (matrix.empty() || matrix[0].empty())
            return -1;
        
        int l = matrix[0][0], r = matrix.back().back();
        while (l < r) {
            int m = l + (long long)r >> 1;
            if (numbers_less_than_or_equal(matrix, m) >= k)
                r = m;
            else
                l = m + 1;
        }
        return l;
    }
};
