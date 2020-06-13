class Solution {
public:
    // Time: O(n)
    // Space: O(1)
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0, j = numbers.size() - 1; i < j; ++i) {
            while (numbers[j] + numbers[i] > target)
                --j;
            
            if (numbers[i] + numbers[j] == target)
                return {i + 1, j + 1};
        }
        return {};
    }
};
