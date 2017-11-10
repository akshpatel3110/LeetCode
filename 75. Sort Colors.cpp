/* 
input: 102201110 
output: 000111122

Invariant: 000XXXXXXXX2222
              r  i   b      (r <= i <= b)
              
000111122
   r
       i
      b
        

*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int r = 0;
        int i = 0;
        int b = nums.size() - 1;
        while (i <= b) {
            if (nums[i] == 0) {
                swap(nums[i], nums[r]);
                ++i;
                ++r;
            } else if (nums[i] == 1) {
                ++i;
            } else {
                swap(nums[i], nums[b]);
                --b;
            }
        }
    }
};
