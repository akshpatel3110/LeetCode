class Solution {
public:
    unordered_map<string, int> dp; // state -> min step
    unordered_map<char, int> cnt; // for hand
    int res = INT_MAX;
    
    string hand_state() {
        string state;
        for (auto [k, v] : cnt) state += to_string(v);
        return state;
    }
    
    string convert(string s) {
        int n = s.size();
        bool removed = true;
        while (removed) {
            removed = false;
            for (int i = 0; i < n; ++i) {
                int j = i + 1;
                while (j < s.size() && s[j] == s[i]) ++j;
                if (j - i >= 3) {
                    s = s.substr(0, i) + s.substr(j);
                    removed = true;
                    break;
                }
            }
        }
        return s;
    }
    
    void dfs(const string & board, const string & hand) {
        auto o_state = board + '#' + hand;
        if (dp[o_state] >= res) return;
        for (auto [k, v] : cnt) {
            if (v) {
                --cnt[k];
                auto n_hand = hand_state();
                for (int i = 0; i <= board.size(); ++i) {
                    auto n_board = convert(board.substr(0, i) + k + board.substr(i));
                    auto n_state = n_board + '#' + n_hand;
                    if (!dp.count(n_state) || dp[o_state] + 1 < dp[n_state]) {
                        dp[n_state] = dp[o_state] + 1;
                        if (n_board.empty()) res = min(res, dp[n_state]);
                        dfs(n_board, n_hand);    
                    }
                }
                ++cnt[k];
            }
        }
    }
    
    int findMinStep(string board, string hand) {
        for (auto c : hand) ++cnt[c];
        dp[board] = 0;
        dfs(board, hand_state());
        if (res == INT_MAX) return -1;
        return res;
    }
};
