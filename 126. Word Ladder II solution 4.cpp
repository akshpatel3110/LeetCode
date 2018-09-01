// beats 86.01% backward graph and bfs set

class Solution {
public:
    vector<vector<string>> findLadders(string begin_word, string end_word, vector<string> & word_list) {
        unordered_set<string> dic(word_list.cbegin(), word_list.cend());
        if (dic.find(end_word) == dic.end())
            return {};
        
        // we don't consider a path like hit -> ... -> hit -> ...
        dic.erase(begin_word);
        
        int level = 0;
        int word_len = begin_word.size();
        
        unordered_map<string, int> from_pos;
        from_pos[begin_word] = -1; // we can change all positions for the begin word
        
        // we change queue to set here, set helps us do dedup easily so that we
        // won't have the same word in the same level
        unordered_set<string> front{begin_word};
        
        // This is what we add for word ladder II
        unordered_map<string, vector<string>> parents;
        bool end_word_found = false;
        
        while (!front.empty() && !end_word_found) {
            
            // we don't want to have a path like ... -> hot -> ... -> hot -> ...
            for (const string & orig_word : front)
                dic.erase(orig_word);
            
            unordered_set<string> new_front;
            for (const string & orig_word : front) {
                // make a copy for modification since we have to remember the original word to
                // contruct the graph
                string new_word = orig_word;
                for (int pos = 0; pos < word_len; ++pos) {
                    if (pos == from_pos[orig_word])
                        continue;
                    
                    char orig_char = orig_word[pos];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c == orig_char)
                            continue;
                        
                        new_word[pos] = c;
                        if (new_word == end_word) {
                            end_word_found = true;
                            parents[new_word].push_back(orig_word);                             
                        } else if (dic.find(new_word) != dic.end() && !end_word_found) {
                            // dedupped automatically
                            new_front.insert(new_word);
                            parents[new_word].push_back(orig_word);
                            from_pos[new_word] = pos;
                        }
                    }
                    new_word[pos] = orig_char;
                }
            }
            std::swap(front, new_front);
        }
        
        // standard dfs
        vector<vector<string>> res;
        if (end_word_found) {
            vector<string> line{end_word};
            dfs(begin_word, end_word, parents, line, res);
        }
        return res;
    }

private:
    void dfs(const string & begin_word,
             const string & cur_word,
             const unordered_map<string, vector<string>>& parents,
             vector<string> & line,
             vector<vector<string>> & res) {
        if (cur_word == begin_word) {
            res.push_back(vector<string>(line.rbegin(), line.rend()));
            return;
        }
        
        // use at instead of operator [] to avoid construct entry in parent
        // const also guarantees that
        for (const string & word : parents.at(cur_word)) {
            line.push_back(word);
            dfs(begin_word, word, parents, line, res);
            line.pop_back();
        }
    }
};
