class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) 
            return {};
        
        unordered_map<char, string> dic = {
            {'2', "abc"}, {'3', "def"},
            {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"},
            {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };
        
        deque<string> q;
        q.push_back("");
        
        // each digit forms a new level
        for (const char digit: digits) {
            // queue size is changing, take it out now! otherwise we don't know
            // how many items are in the current level.
            int level_items = q.size();
            for (int i = 0; i < level_items; ++i) {        
                const string & s = q.front();
                for (const char c : dic[digit])
                    q.push_back(s + c);
                q.pop_front();
            }
        }
        
        vector<string> res;
        std::move(q.begin(), q.end(), std::back_inserter(res)); 
        return res;
    }
};
