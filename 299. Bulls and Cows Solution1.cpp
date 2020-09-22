class Solution {
public:
    // Time: O(n)
    // Space: O(n)
    string getHint(string secret, string guess) {
        int n = secret.size(), bulls = 0, total = 0;
        unordered_map<char, int> hash;
        for (int i = 0; i < n; ++i) {
            ++hash[secret[i]];
            if (secret[i] == guess[i])
                ++bulls;
        }
        
        for (auto c : guess) {
            if (hash[c]) {
                ++total;
                --hash[c];
            }
        }
        return to_string(bulls) + 'A' + to_string(total - bulls) + 'B';
    }
};
