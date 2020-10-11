using LL = long long;

class Solution {
public:
    unordered_map<LL, int> memo;
    
    int integerReplacement(int n) {
        return dfs(n);
    }
    
    int dfs(LL n) {
        cout << n << endl;
        if (memo.count(n)) return memo[n];
        if (n == 1) return 0;
        if (n % 2 == 0) return memo[n] = dfs(n / 2) + 1;
        return memo[n] = min(dfs(n + 1), dfs(n - 1)) + 1;
    }
};
