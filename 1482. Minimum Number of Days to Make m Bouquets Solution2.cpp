class Solution {
public:
    // Time: O(nlogn + n) = O(nlogn)
    // Space: O(n)
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        vector<pair<int, int>> p;
        for (int i = 0; i < bloomDay.size(); ++i) {
            p.emplace_back(bloomDay[i], i + 1);
        }
        
        sort(p.begin(), p.end());
        vector<int> l(n + 2), r(n + 2);
        int count = 0;
        function<int(int, int)> g = [&](int l, int r) {
            return (r - l + 1) / k;
        };
        
        for (auto [day, i] : p) {
            if (l[i - 1] && r[i + 1]) {
                count = count - g(l[i - 1], i - 1) - g(i + 1, r[i + 1]) + g(l[i - 1], r[i + 1]);
                r[l[i - 1]] = r[i + 1];
                l[r[i + 1]] = l[i - 1];
            } else if (l[i - 1]) {
                count = count - g(l[i - 1], i - 1) + g(l[i - 1], i);
                r[l[i - 1]] = i;
                l[i] = l[i - 1];
            } else if (r[i + 1]) {
                count = count - g(i + 1, r[i + 1]) + g(i, r[i + 1]);
                r[i] = r[i + 1];
                l[r[i + 1]] = i;
            } else {
                count += g(i, i);
                l[i] = r[i] = i;
            }
            
            if (count >= m)
                return day;
        }
        return -1;
    }
};
