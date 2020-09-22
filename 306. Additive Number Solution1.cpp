class Solution {
public:  
    
    string add(string x, string y) {
        string z;
        int i = x.size() - 1, j = y.size() - 1, t = 0;
        while (i >= 0 || j >= 0 || t) {
            if (i >= 0) t += x[i--] - '0';
            if (j >= 0) t += y[j--] - '0';
            z += (t % 10 + '0');
            t /= 10;
        }
        reverse(z.begin(), z.end());
        return z;
    }
    
    bool isAdditiveNumber(string num) {
        for (int i = 0; i < num.size(); ++i)
            for (int j = i + 1; j < num.size() - 1; ++j) {
                int a = -1, b = i, c = j;
                while (true) {
                    // skip preceding zeros
                    if (b - a >= 2 && num[a + 1] == '0' || c - b >= 2 && num[b + 1] == '0')
                        break;
                    
                    auto x = num.substr(a + 1, b - a), y = num.substr(b + 1, c - b);
                    auto z = add(x, y);
                    if (num.substr(c + 1, z.size()) != z)
                        break;
                    
                    a = b, b = c, c += z.size();
                    if (c + 1 == num.size())
                        return true;
                }
            }
        return false;
    }
};
