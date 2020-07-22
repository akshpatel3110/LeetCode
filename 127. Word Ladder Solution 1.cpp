class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.cbegin(), wordList.cend());
        unordered_map<string, int> dist;
        dist[beginWord] = 0;
        queue<string> q;
        q.push(beginWord);
        while (q.size()) {
            auto t = q.front();
            q.pop();

            string r = t;
            for (int i = 0; i < t.size(); ++i) {
                for (char c = 'a'; c <= 'z'; ++c) {
                    t[i] = c;
                    if (words.count(t) && !dist.count(t)) {
                        dist[t] = dist[r] + 1;
                        if (t == endWord) 
                            return dist[t] + 1;
                        
                        q.push(t);
                    }
                }
                t = r;
            }
        }
        return 0;     
    }
};
