class Solution {
public:
    // Time: O(nlogn + nlogK)
    // Space: O(n) 
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        vector<pair<double, int>> workers;
        for (int i = 0; i < quality.size(); ++i) {
            workers.push_back({double(wage[i]) / quality[i], quality[i]});
        }
        
        sort(workers.begin(), workers.end());
        priority_queue<int> pq;
        double res = DBL_MAX, qsum = 0;
        for (auto w : workers) {
            pq.push(w.second);
            qsum += w.second;
            if (pq.size() > K) {
                qsum -= pq.top();
                pq.pop();
            }
            
            if (pq.size() == K) {
                res = min(res, qsum * w.first);
            }
        }
        return res;
    }
};
