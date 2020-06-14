class Solution {
public:
    // Time: O(n)
    // Space: O(1)
    int maxArea(vector<int>& height) {
        int res = 0, i = 0, j = height.size() - 1;
        while (i < j) {
            res = max(res, min(height[i], height[j]) * (j - i));
            if (height[i] < height[j])
                ++i;
            else
                --j;
        }
        return res;
    }
};
