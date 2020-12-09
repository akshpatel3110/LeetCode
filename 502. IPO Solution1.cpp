class Solution {
public:
    // Greedy
    // Time: O(nlogn)
    // Space: O(n)
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        int n = Profits.size();
        vector<pair<int, int>> projects(n);
        for (int i = 0; i < n; ++i) {
            projects[i] = {Capital[i], Profits[i]};    
        }
        sort(projects.begin(), projects.end());
        priority_queue<int> heap;
        int i = 0;
        while (k--) {
            while (i < n && projects[i].first <= W) {
                heap.push(projects[i].second);
                ++i;
            }
            if (heap.size()) {
                W += heap.top();
                heap.pop();
            }
        }
        return W;
        
    }
};
