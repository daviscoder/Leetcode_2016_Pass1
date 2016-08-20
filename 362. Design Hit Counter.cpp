class HitCounter {
public:
    vector<int> hits;
    int prevTime;
    /** Initialize your data structure here. */
    HitCounter() {
        hits.assign (300, 0);
        prevTime = 0;
    }
    
    void adjust (int timestamp) {
        int start = timestamp - 300 + 1;
        if (start > prevTime) {
            hits.clear();
            hits.assign (300, 0);
        }
        else {
            for (int i = prevTime + 1; i <= timestamp; i++)
                hits[(i - 1) % 300] = 0;
        }
    }
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        adjust (timestamp);
        hits[(timestamp - 1) % 300]++;
        prevTime = timestamp;
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        adjust (timestamp);
        return accumulate (hits.begin(), hits.end(), 0);
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */
