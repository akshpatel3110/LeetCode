class MyStack {
public:
    queue<int> a, b;
    
    /** Initialize your data structure here. */
    MyStack() {
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        a.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        while (a.size() > 1) {
            b.push(a.front());
            a.pop();
        }
        int t = a.front();
        a.pop();
        while (b.size()) {
            a.push(b.front());
            b.pop();
        }
        return t;
    }
    
    /** Get the top element. */
    int top() {
        while (a.size() > 1) {
            b.push(a.front());
            a.pop();
        }
        int t = a.front();
        a.pop();
        while (b.size()) {
            a.push(b.front());
            b.pop();
        }
        a.push(t);
        return t;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return a.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
