class Queue {
public:
    stack <int> myQueue;
    // Push element x to the back of queue.
    void push(int x) {
        stack<int> tmp;
        while (!myQueue.empty()) {
            tmp.push (myQueue.top());
            myQueue.pop();
        }
        tmp.push (x);
        while (!tmp.empty()) {
            myQueue.push (tmp.top());
            tmp.pop();
        }
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if (!myQueue.empty())
            myQueue.pop();
    }

    // Get the front element.
    int peek(void) {
        if (!myQueue.empty())
            return myQueue.top();
        return 0;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return myQueue.empty();
    }
};
