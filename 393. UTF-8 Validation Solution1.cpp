class Solution {
public:
    int get(int x, int i) {
        return x >> i & 1;
    }
    
    // Time: O(n)
    // Space: O(1)
    bool validUtf8(vector<int>& data) {
        for (int i = 0; i < data.size(); ++i) {
            if (!get(data[i], 7)) continue;
            int cnt = 0; // cnt is the number of consecutive 1s
            while (cnt <= 4 && get(data[i], 7 - cnt)) ++cnt;
            if (cnt == 1 || cnt > 4) return false;
            for (int j = 1; j < cnt; ++j) {
                int k = i + j;
                if (k >= data.size()) return false;
                if (!(get(data[k], 7) && !get(data[k], 6))) return false;
            }
            i += cnt - 1;
        }
        return true;
    }
};
