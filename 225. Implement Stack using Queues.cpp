class Stack {
public:
    queue <int> myQueue;
    // Push element x onto stack.
    void push(int x) {
        queue<int> tmp;
        tmp.push (x);
        while (myQueue.empty() == false) {
            tmp.push (myQueue.front());
            myQueue.pop();
        }
        while (tmp.empty() == false) {
            myQueue.push (tmp.front());
            tmp.pop();
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        myQueue.pop();
    }

    // Get the top element.
    int top() {
        return myQueue.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return myQueue.empty();
    }
};
