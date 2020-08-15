class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, candidate;
        for (int num : nums) {
            if (count == 0)
                candidate = num;
            if (candidate == num)
                ++count;
            else
                --count;
        }
        return candidate;
    }
};
