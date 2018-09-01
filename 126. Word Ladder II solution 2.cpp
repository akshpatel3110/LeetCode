// beats 77.91% backward graph and queue

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
        
        queue<string> q;
        q.push(begin_word);
        
        // This is what we add for word ladder II
        unordered_map<string, int> levels{{begin_word, 1}};
        unordered_map<string, vector<string>> parents;
        bool end_word_found = false;
        
        while (!q.empty() && !end_word_found) {
            ++level;
            
            // queue size is changing, take it out now! otherwise we don't know
            // how many items are in the current level.
            int level_items = q.size();
            for (int i = 0; i < level_items; ++i) {
                string orig_word = q.front();
                
                // make a copy for modification since we have to remember the original word to
                // contruct the graph
                string new_word = orig_word;
                q.pop();
                for (int pos = 0; pos < word_len; ++pos) {
                    if (pos == from_pos[orig_word])
                        continue;
                    
                    char orig_char = orig_word[pos];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c == orig_char)
                            continue;
                        
                        new_word[pos] = c;
                        if (new_word == end_word || dic.find(new_word) != dic.end()) {
                            // First time encounter new_word, 
                            levels[new_word] = level + 1;
                            parents[new_word].push_back(orig_word);
                            
                            // we don't want to have a path like ... hot -> ... -> hot
                            dic.erase(new_word);
                            if (new_word == end_word) {
                                end_word_found = true;
                            } else {
                                // queue new_word to the next level
                                q.push(new_word);
                                from_pos[new_word] = pos;
                            }
                        } else {
                            auto it = levels.find(new_word);
                            if (it != levels.end() && it->second == level + 1) {
                                // if new_word is already constructed and we are on the previous level, put it in the graph
                                parents[new_word].push_back(orig_word);
                            }
                            
                            // otherwise do nothing
                        }
                        new_word[pos] = orig_char;
                    }
                }
            }
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
        // const also gurantees that
        for (const string & word : parents.at(cur_word)) {
            line.push_back(word);
            dfs(begin_word, word, parents, line, res);
            line.pop_back();
        }
    }
};
