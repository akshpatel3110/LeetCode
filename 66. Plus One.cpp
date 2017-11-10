/*
digits [3, 5, 7]
              i
 

digits [3, 6, 0]
           i
            
digits [1, 0, 0, 0]
     i
 
*/


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for (int i = n - 1; i >=0; --i) {
            if (digits[i] == 9) {
                digits[i] = 0;
            } else {
                ++digits[i];
                return digits;
            }
        }
        
        digits[0] = 1;
        digits.push_back(0);
        return digits;
    }
};
