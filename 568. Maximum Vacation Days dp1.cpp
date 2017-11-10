/*
Brute force
O(N ^ K)

DP
O(K * N * N) time
O(NK) space --> O(N) space

1. define subproblems
dp[i][j]: The maximum vacation days we can get in week i staying at city j
number of subproblems O(K * N)

2. guess
In week i - 1, which city we are in.
number of choices O(N)

3. relate subproblem solutions
dp[i][j] = max(dp[i - 1][k] + days[j][i]) (k = {previous reachable cities}, if we can go from previous city k to city j)
time per subproblem O(N)

corner case: week 0, the previous city is 0, no guesses
dp[0][j] = days[j][0] if city j is reachable


4. topological order
week 0 to K - 1

5. original problem
max(dp[K - 1][j]) (j = 0, 1, ... N)

*/



class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int N = flights.size();
        int K = days[0].size();
        
        vector<vector<int>> dp(K, vector<int>(N, 0));
        vector<vector<bool>> reach(K, vector<bool>(N, false));

        // first week, no guesses for the previous city
        for (int city = 0; city < N; ++city)
            if (city == 0 || flights[0][city]) {
                dp[0][city] = days[city][0];
                reach[0][city] = true;
            }
        
        
        // topological order (week)
        for (int week = 1; week < K; ++week) {
            // current city
            for (int city = 0; city < N; ++city) {
                // Subproblem: guess a previous city
                for (int prevCity = 0; prevCity < N; ++prevCity) {
                    if (reach[week - 1][prevCity] && (city == prevCity || flights[prevCity][city])) {
                        dp[week][city] = max(dp[week][city], dp[week - 1][prevCity] + days[city][week]);
                        reach[week][city] = true;
                    }   
                }
            }
        }
        
        int res = 0;
        for (int city = 0; city < N; ++city)
            res = max(res, dp[K - 1][city]);
        
        return res;
        
    }
    
};
