class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> s;
        for (int num : nums) {
            if (s.count(num))
                s.erase(num);
            else
                s.insert(num);
        }
        return *s.begin();
    }
};
