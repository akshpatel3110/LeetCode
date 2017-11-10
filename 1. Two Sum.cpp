/*
search for target - nums[i] backward

[2, 7, 11, 15]  target = 9 
    j   i

*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> dic;
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            int numberToFind = target - nums[i];
            if (dic.find(numberToFind) != dic.end()) {
                res.push_back(dic[numberToFind]);
                res.push_back(i);
                return res;
            }
            dic[nums[i]] = i;
        }
        return res;
    }
};
