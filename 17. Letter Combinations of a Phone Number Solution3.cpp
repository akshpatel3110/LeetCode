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
        
        vector<string> front{""};
        
        // each digit forms a new level
        for (const char digit: digits) {
            vector<string> new_front;
            for (const string & s : front)
                for (const char c : dic[digit])
                    new_front.push_back(s + c);
            std::swap(front, new_front);
        }
        
        return front;
    }
};
