// Time O(2n) = O(n)
// Space O(n)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set(nums.begin(), nums.end());
        int res = 0;
        for (int num : nums) {
            if (num_set.find(num - 1) == num_set.end()) {
                int cur_num = num;
                int cur_streak = 1;

                // each number is visited at most twice
                while (num_set.find(cur_num + 1) != num_set.end()) {
                    ++cur_num;
                    ++cur_streak;
                }
                res = max(res, cur_streak);
            }
        }
        return res;
    }
};
