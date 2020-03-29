class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0;
        for (int i = 0; i < nums.size(); ++i) {
            b = ~a & (b ^ nums[i]);
            a = ~b & (a ^ nums[i]);
        }
        return b;
    }
};
