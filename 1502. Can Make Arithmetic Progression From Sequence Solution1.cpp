class Solution {
public:
    // Time: O(nlogn)
    // Space: O(1)
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        for (int i = 2; i < arr.size(); ++i) {
            if (arr[i] - arr[i - 1] != arr[1] - arr[0])
                return false;
        }
        return true;
    }
};
