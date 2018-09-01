// beats 81.49% forward graph and bfs set

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
        unordered_map<string, vector<string>> children;
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
                            children[orig_word].push_back(new_word);                             
                        } else if (dic.find(new_word) != dic.end() && !end_word_found) {
                            // dedupped automatically
                            new_front.insert(new_word);
                            children[orig_word].push_back(new_word);
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
            vector<string> line{begin_word};
            dfs(end_word, begin_word, children, line, res);
        }
        return res;
    }

private:
    void dfs(const string & end_word,
             const string & cur_word,
             const unordered_map<string, vector<string>>& children,
             vector<string> & line,
             vector<vector<string>> & res) {
        if (cur_word == end_word) {
            res.push_back(vector<string>(line.begin(), line.end()));
            return;
        }

        auto it = children.find(cur_word);
        if (it != children.end()) {
            for (const string & word : it->second) {
                line.push_back(word);
                dfs(end_word, word, children, line, res);
                line.pop_back();
            }
        }
    }
};
