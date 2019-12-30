// Time: O(n)
// Space: O(1)
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0, tens = 0;
        for (auto b : bills) {
            if (b == 5) {
                ++fives;
            } else if (b == 10) {
                if (!fives)
                    return false;
                --fives;
                ++tens;
            } else {
                if (fives && tens) {
                    --fives;
                    --tens;
                } else if (fives >= 3) {
                    fives -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
