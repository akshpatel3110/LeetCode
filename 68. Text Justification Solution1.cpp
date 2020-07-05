class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int w) {
        vector<string> res;
        // l is the length for characters
        for (int i = 0, j, l; i < words.size(); i += j) {
            j = l = 0;
            while (i + j < words.size() && l + words[i + j].size() + j <= w) {
                l += words[i + j].size();
                ++j;
            }
            string line = words[i];
            for (int k = 1; k < j; ++k) {
                // last line
                if (i + j >= words.size()) line += " ";
                else line += string((w - l) / (j - 1) + (k <= (w - l) % (j - 1)), ' ');
                line += words[i + k];
            }
            line += string(w - line.size(), ' ');
            res.push_back(move(line));
        }
        return res;        
    }
};
