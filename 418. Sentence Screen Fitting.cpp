/*
time O(rows * word length)
space O(number of characters in the reformatted sentence) = O(number of words * word length)

Reformatted sentence
["ab", "cde", "f"] --> "ab cde f "

count: how many characters of the reformatted sentence is on the screen
count % length of reformatted sentence: the starting position of the next row

Answer: count / length of reformatted sentence

length: 9
count = (3 + 4 + 5 + 4 + 5) / 9 = 2

row 5
col 4


ab cde f ab cde f ab cde f....
XXX
   XXXX
       XXXXX
            XXXX
                XXXXX
                
                  


*/


class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        string s;
        for (const auto& sen: sentence) {
            s += sen;
            s += " ";
        }
        
        int count{0};
        int n = s.size();
        for (int i = 0; i < rows; ++i) {
            count += cols;
            if (s[count % n] == ' ') {
                ++count;
            } else {
                while (count > 0 && s[(count - 1) % n] != ' ')
                    --count;
            }
        }
        
        return count / n;
        
        
    }
};
