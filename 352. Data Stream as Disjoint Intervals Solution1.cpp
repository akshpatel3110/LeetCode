using LL = long long;
using PLL = pair<LL, LL>;
#define a first
#define b second

class SummaryRanges {
public:    
    set<PLL> s;
    
    /** Initialize your data structure here. */
    SummaryRanges() {
        s.emplace(LLONG_MIN, LLONG_MIN);
        s.emplace(LLONG_MAX, LLONG_MAX);
    }
    
    // Time: O(logn)
    void addNum(int x) {
        auto r = s.upper_bound({x, INT_MAX});
        auto l = r;
        --l;
        if (l->b >= x) return;
        if (l->b == x - 1 && r->a == x + 1) {
            s.emplace(l->a, r->b);
            s.erase(l);
            s.erase(r);
        } else if (l->b == x - 1) {
            s.emplace(l->a, x);
            s.erase(l);
        } else if (r->a == x + 1) {
            s.emplace(x, r->b);
            s.erase(r);
        } else {
            s.emplace(x, x);
        }
    }
    
    // Time: O(n)
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        for (auto p : s) {
            if (p.a != LLONG_MIN && p.a != LLONG_MAX)
                res.push_back({(int)p.a, (int)p.b});
        }
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
