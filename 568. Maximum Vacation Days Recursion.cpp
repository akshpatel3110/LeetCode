class Solution {
public:
    int maxVacationDays(const vector<vector<int>>& flights, const vector<vector<int>>& days) {
        int N = flights.size();
        int K = days.size();
        int res = 0;
        dfs(flights, days, 0, 0, 0, N, K, res);
        return res;
    }
    
    void dfs(const vector<vector<int>>& flights, const vector<vector<int>>& days, int city, int week, int sum, int N, int K, int& res) {
        if (week == K) {
            res = max(res, sum);
            return;
        }
        
        for (int nextCity = 0; nextCity < N; ++nextCity) {
            if (city == nextCity || flights[city][nextCity]) {
                dfs(flights, days, nextCity, week + 1, sum + days[nextCity][week], N, K, res);
            }
        }
        
    }
};
