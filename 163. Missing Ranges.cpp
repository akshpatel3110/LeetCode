/*
Example 1
[0, 0, 1, 3, 50, 75]
                     i
 
lower = 76
upper = 99

Output ["2", "4->49", "51->74", "76->99"]
2
4->49
51->74
76->99



Example 2
[-2147483648,-2147483648,0,2147483647,2147483647]
                              i


lower = 1
upper = 2147483647

Output: ["-2147483647->-1","1->2147483646"]
-2147483647->-1
1->2147483646


*/

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        for (const int num : nums) {
            if (num == INT_MIN) {
                lower = num + 1;
                continue;
            }
            
            if (lower < num - 1)
                res.push_back(to_string(lower) + "->" + to_string(num - 1));
            else if (lower == num - 1)
                res.push_back(to_string(lower));
            
            if (num == INT_MAX)
                return res;
            
            lower = num + 1;
        }
        
        if (lower < upper)
            res.push_back(to_string(lower) + "->" + to_string(upper));
        else if (lower == upper)
            res.push_back(to_string(lower));

        return res;

    }
    
};
