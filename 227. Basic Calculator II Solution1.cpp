class Solution {
public:
    stack<int> num;
    stack<char> op;
    
    void calc() {
        int b = num.top(); num.pop();
        int a = num.top(); num.pop();
        char c = op.top(); op.pop();
        int res;

        if (c == '+') 
            res = a + b;
        else if (c == '-') 
            res = a - b;
        else if (c == '*') 
            res = a * b;
        else 
            res = a / b;
        
        num.push(res);
    }

    // Time: O(n)
    // Space: O(n)
    int calculate(string s) {
        unordered_map<char, int> pr;
        pr['+'] = pr['-'] = 1, pr['*'] = pr['/'] = 2;
        for (int i = 0; i < s.size(); ++i) {
            auto c = s[i];
            if (c == ' ') 
                continue;

            if (isdigit(c)) {
                int x = 0, j = i;
                while (j < s.size() && isdigit(s[j])) 
                    x = x * 10 + (s[j++] - '0');

                num.push(x);
                i = j - 1;
            } else {
                // use while not if "1*2-3/4+5*6"
                // When we come to +, we should evaluate both / and -
                // evaluate later will give us a wrong result.
                while (op.size() && pr[op.top()] >= pr[c]) 
                    calc();
                
                op.push(c);
            }
        }
        
        // again for "1*2-3/4+5*6", we have multiple ops to evaluate
        while (op.size()) 
            calc();
        
        return num.top();
    }
};
