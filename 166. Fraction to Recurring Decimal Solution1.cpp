class Solution {
public:
    // Time: O(denominator)
    // Space: O(denominator)
    string fractionToDecimal(int numerator, int denominator) {
        using LL = long long;
        LL x = numerator, y = denominator;
        if (x % y == 0)
            return to_string(x / y);
        
        string res;
        if ((x > 0) ^ (y > 0))
            res += '-';
        
        x = abs(x), y = abs(y);
        res += to_string(x / y) + '.';
        x %= y;
        unordered_map<LL, int> hash;
        while (x) {
            hash[x] = res.size();
            x *= 10;
            res += to_string(x / y);
            x %= y;
            if (hash.count(x)) {
                res = res.substr(0, hash[x]) + '(' + res.substr(hash[x]) + ')';
                break;
            }
        }
        return res;
    }
};
