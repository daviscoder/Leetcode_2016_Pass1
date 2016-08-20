class MinStack {
private:
    stack<int> s;
    stack<int> minStack;
    int min;
public:
    /** initialize your data structure here. */
    MinStack() {
        this->min = INT_MAX;
    }
    
    void push(int x) {
        if (x < min)
            min = x;
        s.push (x);
        minStack.push (min);
    }
    
    void pop() {
        s.pop ();
        minStack.pop();
        if (minStack.empty())
            min = INT_MAX;
        else
            min = minStack.top();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
