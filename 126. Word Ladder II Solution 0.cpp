class Solution {
public:
    unordered_set<string> words;
    unordered_map<string, int> dist;
    queue<string> q;
    vector<vector<string>> res;
    vector<string> path;
    string beginWord;

    vector<vector<string>> findLadders(string _beginWord, string endWord, vector<string>& wordList) {
        for (auto word: wordList) words.insert(word);
        beginWord = _beginWord;
        dist[beginWord] = 0;
        q.push(beginWord);
        while (q.size()) {
            auto t = q.front();
            q.pop();

            string r = t;
            for (int i = 0; i < t.size(); ++i) {
                t = r;
                for (char c = 'a'; c <= 'z'; ++c) {
                    t[i] = c;
                    if (words.count(t) && !dist.count(t)) {
                        dist[t] = dist[r] + 1;
                        if (t == endWord) 
                            break;
                        
                        q.push(t);
                    }
                }
            }
        }

        if (dist.count(endWord) == 0) 
            return res;
        
        path.push_back(endWord);
        dfs(endWord);
        return res;
    }

    void dfs(string t) {
        if (t == beginWord) {
            res.push_back(vector<string>(path.rbegin(), path.rend()));
        } else {
            string r = t;
            for (int i = 0; i < t.size(); ++i) {
                t = r;
                for (char c = 'a'; c <= 'z'; ++c) {
                    t[i] = c;
                    if (dist.count(t) && dist[t] + 1 == dist[r]) {
                        path.push_back(t);
                        dfs(t);
                        path.pop_back();
                    }
                }
            }
        }
    }
};
