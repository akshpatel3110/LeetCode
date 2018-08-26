// Time O(26 * word_len * size of word_list) = O(word_len * size of word_list)
// Space O(size of word_list)

class Solution {
public:
    int ladderLength(string begin_word, string end_word, vector<string>& word_list) {
        unordered_set<string> dic(word_list.cbegin(), word_list.cend());
        if (dic.find(end_word) == dic.end())
            return 0;
        
        int level = 0;
        int word_len = begin_word.size();
        
        unordered_map<string, int> from_pos;
        from_pos[begin_word] = -1; // we can change all positions for the begin word
        
        queue<string> q;
        q.push(begin_word);
        
        while (!q.empty()) {
            ++level;
            
            // queue size is changing, take it out now! otherwise we don't know
            // how many items are in the current level.
            int level_items = q.size();
            for (int i = 0; i < level_items; ++i) {
                string word = q.front();
                q.pop();
                for (int pos = 0; pos < word_len; ++pos) {
                    if (pos == from_pos[word])
                        continue;
                    
                    char orig_char = word[pos];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        word[pos] = c;
                        if (word == end_word)
                            return level + 1;
                        
                        if (dic.find(word) == dic.end())
                            continue;
                        
                        from_pos[word] = pos;
                        
                        // we don't want to have a path like hit -> ... -> hit
                        dic.erase(word);
                        
                        // queue word to the next level
                        q.push(word);
                    }
                    word[pos] = orig_char;
                }
                from_pos.erase(word);
            }
        }
        
        return 0;
    }
};
