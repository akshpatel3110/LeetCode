class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int x, int y) {
            string sx = to_string(x);
            string sy = to_string(y);
            return sx + sy > sy + sx;
        });
        
        string res;
        for (auto num : nums)
            res += to_string(num);
        
        return res[0] == '0' ? "0" : res;
    }
};
