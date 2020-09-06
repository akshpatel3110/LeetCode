class Solution {
public:
    stack<char> op;
    stack<int> num;
    
    void calc() {
        int b = num.top(); num.pop();
        int a = num.top(); num.pop();
        char c = op.top(); op.pop();
        int res;

        if (c == '+')
            res = a + b;
        else
            res = a - b;

        num.push(res);
    }

    // Time: O(n)
    // Space: O(n)
    int calculate(string s) {
        for (int i = 0; i < s.size(); ++i) {
            auto c = s[i];
            if (c == ' ') 
                continue;
            
            if (c == '+' || c == '-' || c == '(') {
                op.push(c);
            } else if (c == ')') {
                op.pop();
                // 1 + (2 + 3), calculate 1 + 5
                if (op.size() && op.top() != '(') {
                    calc();
                }
            } else {
                // digit
                int j = i;
                while (j < s.size() && isdigit(s[j]))
                    ++j;
                
                num.push(atoi(s.substr(i, j - i).c_str()));
                i = j - 1;
                if (op.size() && op.top() != '(') {
                    calc();
                }
            }
        }
        return num.top();
    }
};
