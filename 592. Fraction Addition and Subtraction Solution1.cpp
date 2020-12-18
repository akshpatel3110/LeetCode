class Solution {
public:
    string fractionAddition(string expression) {
        istringstream is(expression);
        int num = 0, dem = 0, a = 0, b = 1; 
        char c;
        while (is >> num >> c >> dem) {
            a = a * dem + num * b;
            b *= dem;
            int z = abs(gcd(a, b));
            a /= z;
            b /= z;
        }
        return to_string(a) + "/" + to_string(b);
    }
    
    int gcd(int a, int b) {
        return (b == 0) ? a : gcd(b, a % b);
    }
};
