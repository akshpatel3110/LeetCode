class Solution {
public:
    // Time: O(n)
    // Space: O(1)
    int thirdMax(vector<int>& nums) {
        long long a = LLONG_MIN, b = LLONG_MIN, c = LLONG_MIN, cnt = 0;
        for (auto x : nums) {
            if (x > a) c = b, b = a, a = x, ++cnt;
            else if (x > b && x < a) c = b, b = x, ++cnt;
            else if (x > c && x < b) c = x, ++cnt;
        }
        if (cnt < 3) return a;
        return c;
        
    }
};
