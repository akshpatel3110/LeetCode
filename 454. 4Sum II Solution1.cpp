class Solution {
public:
    // Time: O(n ^ 2)
    // Space: O(n ^ 2)
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> hash;
        for (auto c : C)
            for (auto d : D)
                ++hash[c + d];
        
        int res = 0;
        for (auto a : A)
            for (auto b : B)
                res += hash[-(a + b)];
        return res;
    }
};
