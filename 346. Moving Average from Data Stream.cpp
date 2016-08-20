class MovingAverage {
private:
    std::queue<int> my_queue;
    int total;
    int size;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        this->size = size;
        this->total = 0;
    }
    
    double next(int val) {
        if (my_queue.size() >= this->size) {
            total -= my_queue.front();
            my_queue.pop();
        }
        my_queue.push(val);
        total += val;
        return (double) total / my_queue.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
