class Solution {
public:
    // Time: O(n)
    // Space: O(1)
    int compress(vector<char>& s) {
        int k = 0;
        for (int i = 0; i < s.size();) {
            int j = i + 1;
            while (j < s.size() && s[i] == s[j]) ++j;
            s[k++] = s[i];
            if (j - i > 1) {
                for (char c : to_string(j - i))
                    s[k++] = c;
            }
            i = j;
        }
        return k;
    }
};
