class Solution {
public:
    // Time: ignore push_back, O(2 ^ 9)
    // Space: ignore res, path is moved, O(1)
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        for (int number = 0; number < 1 << 9; ++number) {
            vector<int> path;
            int sum = 0;
            for (int i = 0; i < 9; ++i) {
                if (number & (1 << i)) {
                    path.push_back(i + 1);
                    sum += (i + 1);
                }
            }
            
            if (sum == n && path.size() == k) {
                res.push_back(std::move(path));
            }
        }
        
        return res;
    }
};
