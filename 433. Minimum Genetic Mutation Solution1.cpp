class Solution {
public:
    // variation of word ladder
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> hash{bank.begin(), bank.end()};
        unordered_map<string, int> dist;
        dist[start] = 0;
        queue<string> q;
        q.push(start);
        const string candidates = "ATCG";
        while (q.size()) {
            auto t = q.front();
            q.pop();
            for (int i = 0; i < t.size(); ++i) {
                auto s = t;
                for (char c : candidates) {
                    s[i] = c;
                    if (hash.count(s) && !dist.count(s)) {
                        dist[s] = dist[t] + 1;
                        if (s == end) return dist[s];
                        q.push(s);
                    }
                }
            }
        }
        return -1;
    }
};
