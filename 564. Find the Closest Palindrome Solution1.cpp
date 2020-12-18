class Solution {
public:
    string nearestPalindromic(string n) {
        using LL = long long;
        int len = n.size();
        set<LL> st;
        st.insert((LL)pow(10, len - 1) - 1);
        st.insert((LL)pow(10, len) + 1);
        LL m = stoll(n.substr(0, (len + 1) / 2));
        for (LL i = m - 1; i <= m + 1; ++i) {
            auto a = to_string(i);
            auto b = a;
            reverse(b.begin(), b.end());
            if (len % 2) st.insert(stoll(a + b.substr(1)));
            else st.insert(stoll(a + b));
        }

        LL N = stoll(n);
        st.erase(N);
        LL res = LLONG_MAX;
        for (auto x: st)
            if (abs(x - N) < abs(res - N))
                res = x;
        return to_string(res);       
    }
};
