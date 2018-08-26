// Time O(26 * word_len * size of word_list) = O(word_len * size of word_list)
// Space O(size of word_list)

class Solution {
public:
    int ladderLength(string begin_word, string end_word, vector<string>& wordList) {
        unordered_set<string> dic(wordList.begin(), wordList.end());        
        if (dic.find(end_word) == dic.end()) 
            return 0;

         // we don't want to have a path like hit -> ... -> hit -> ...
         dic.erase(begin_word);

        int level = 0;
        int word_len = begin_word.length();
        
        unordered_set<string> front{begin_word};
        unordered_set<string> back{end_word};      
        
        while (!front.empty() && !back.empty()) {
            ++level;
            
            // front is always the smaller set
            if (front.size() > back.size())
                std::swap(front, back);
                        
            unordered_set<string> new_front;
            
            for (string word : front) {
                for (int pos = 0; pos < word_len; ++pos) {
                    char orig_char = word[pos];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        word[pos] = c;
                        if (back.find(word) != back.end())
                            return level + 1;
                        
                        if (dic.find(word) == dic.end())
                            continue;
                       
                        // we don't want to have a path like ... -> hot -> ... -> hot -> ...
                        dic.erase(word);
                        
                        // queue word to the next level
                        new_front.insert(word);
                    }
                    word[pos] = orig_char;
                }
            }
            
            std::swap(front, new_front);
        }
        
        return 0;
        
    }
};
