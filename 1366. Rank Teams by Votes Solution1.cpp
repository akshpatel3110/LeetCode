class Solution {
public:
    // Time: O(mn + 26nlog26) = O(mn)
    // Space: O(26n) = O(n)
    string rankTeams(vector<string>& votes) {
        int n = votes[0].size();
        vector<vector<int>> ranks(26, vector<int>(n + 1));
        
        for (int i = 0; i < 26; ++i)
            ranks[i][n] = -i;
        
        for (auto & v : votes)
            for (int i = 0; i < n; ++i)
                ++ranks[v[i] - 'A'][i];
        
        sort(ranks.begin(), ranks.end(), greater<vector<int>>());
        
        string res;
        for (int i = 0; i < n; ++i)
            res += -ranks[i][n] + 'A';
        
        return res;        
    }
};
