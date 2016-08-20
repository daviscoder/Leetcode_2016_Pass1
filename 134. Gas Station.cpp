class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (gas.size() <= 0)
            return -1;
        int remain = 0, start = 0, sum = 0;
        for (int i = 0; i < gas.size(); i++) {
            sum += gas[i] - cost[i];
            if (remain + gas[i] - cost[i] < 0) {
                start = i + 1;
                remain = 0;
            }
            else {
                remain += gas[i] - cost[i];
            }
        }
        return sum >= 0? start : -1;
    }
};
