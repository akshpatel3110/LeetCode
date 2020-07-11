class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> cnt(k);
        for (int x : arr) {
            ++cnt[(x % k + k) % k];
        }
        
        if (cnt[0] % 2) return false;
        for (int i = 1, j = k - 1; i <= j; ++i, --j) {
            if (i == j) {
                if (cnt[i] % 2) return false;
            } else {
                if (cnt[i] != cnt[j]) return false;
            }
        }
        return true;
    }
};
