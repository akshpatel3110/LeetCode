class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hash;
        for (auto num : nums) {
            if (hash.count(num)) return true;
            else hash.insert(num);
        }
        return false;
    }
};
