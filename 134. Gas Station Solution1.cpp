class Solution {
public:
    // Time: O(n)
    // Space: O(1)
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int i = 0;
        while (i < n) {
            int left = 0;
            int j = 0;
            while (j < n) {
                int k = (i + j) % n;
                left += gas[k] - cost[k];
                if (left < 0)
                    break;
                ++j;
            }
            if (j == n)
                return i;
            
            i = i + j + 1;
        }
        return -1;
    }
};
