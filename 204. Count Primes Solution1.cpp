class Solution {
public:
    // Time: O(n)
    // Space: O(n)
    int countPrimes(int n) {
        vector<int> primes;
        vector<int> marked(n);
        for (int i = 2; i < n; ++i) {
            if (!marked[i])
                primes.push_back(i);
            
            for (int j = 0; i * primes[j] < n; ++j) {
                marked[i * primes[j]] = true;
                if (i % primes[j] == 0)
                    break;
            }
        }
        return primes.size();
    }
};
