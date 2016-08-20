// https://segmentfault.com/a/1190000003794831
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int res = 0;
        vector<int> stats (citations.size() + 1, 0);
        for (int i = 0; i < citations.size(); i++)
            stats[citations[i] < stats.size()? citations[i] : stats.size() - 1]++;
        for (int i = stats.size() - 1; i > 0; i--) {
            res += stats[i];
            if (res >= i)
                return i;
        }
        return 0;
    }
};
