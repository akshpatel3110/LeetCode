class Solution {
public:
    int magicalString(int n) {
        string s = "122";
        for (int i = 2, num = 1; s.size() < n; ++i, num = 3 - num)
            for (int j = 0; j < s[i] - '0'; ++j)
                s += to_string(num);
        
        int res = 0;
        for (int i = 0; i < n; ++i)
            if (s[i] == '1')
                ++res;
        return res;
    }
};`
