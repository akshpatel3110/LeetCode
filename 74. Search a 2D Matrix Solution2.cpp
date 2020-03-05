class Solution {
public:
    // Time: O(m + n)
    // Space: O(1)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty())
            return false;
        
        int i = 0, j = matrix[0].size() - 1;
        while (i < matrix.size() && j >= 0) {
            if (matrix[i][j] == target)
                return true;
            
            if (matrix[i][j] < target)
                ++i;
            else
                --j;
        }
        return false;
    }
};
