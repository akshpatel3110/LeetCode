/*
dir                  
    subdir1
        file1.ext
        subsubdir1
    subdir2
        subsubdir2
            file2.ext

maxlen = 9 + 23 = 32

levelLength
0 : 0
1 : 4
2 : 12
3 : 23



*/

class Solution {
public:
    int lengthLongestPath(string input) {
        int maxlen = 0, count = 0, level = 1;
        bool isFile = false;
        unordered_map<int, int> levelLength;
        
        int i = 0;
        int length = input.size();
        while (i < length) {
            while (input[i] == '\t') {
                ++level;
                ++i;
            }
            
            while (i < length && input[i] != '\n') {
                if (input[i] == '.')
                    isFile = true;
                
                ++count;
                ++i;
            }
            
            if (isFile) {
                maxlen = max(maxlen, levelLength[level - 1] + count);
            } else {
                levelLength[level] = levelLength[level - 1] + count + 1;
            }
            
            count = 0;
            level = 1;
            isFile = false;
            
            ++i;
        }
        
        return maxlen;
    }
};
