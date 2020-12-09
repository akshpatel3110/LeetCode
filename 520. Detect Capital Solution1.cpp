class Solution {
public:
    bool check(char c) {
        return c >= 'A' && c <= 'Z';
    }
    
    // Time: O(n)
    // Space: O(1)
    bool detectCapitalUse(string word) {
        int cnt = 0, n = word.size();
        for (auto c : word) {
            if (check(c)) ++cnt;
        }
        return cnt == 0 || cnt == n || (cnt == 1 && check(word[0]));
    }
};
