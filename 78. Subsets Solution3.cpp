class Solution {
public:
    // Time: two for loops O(n * 2 ^ n)
    // Space: O(1)
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        for (int number = 0; number < 1 << nums.size(); ++number) {
            vector<int> path;
            for (int i = 0; i < nums.size(); ++i)
                if (number >> i & 1)
                    path.push_back(nums[i]);
            res.push_back(std::move(path));
        }
        return res;
    }
};
