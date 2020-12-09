class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> lines{
            "qwertyuiop",
            "asdfghjkl",
            "zxcvbnm"
        };
        
        unordered_map<char, int> hash;
        for (int i = 0; i < 3; ++i)
            for (auto c: lines[i])
                hash[c] = i;

        vector<string> res;
        for (auto & word: words) {
            set<int> st;
            bool flag = true;
            for (auto c: word) {
                st.insert(hash[tolower(c)]);
                if (st.size() > 1) {
                    flag = false;
                    break;
                }
            }
            if (flag) res.push_back(word);
        }
        return res;       
    }
};
