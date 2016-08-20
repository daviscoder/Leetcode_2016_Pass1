/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    static bool myfunction (Interval i, Interval j) {
        if (i.start <= j.start)
            return true;
        return false;
    }
    
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.size() <= 0)
            return 0;
        int res = 0;
        sort (intervals.begin(), intervals.end(), myfunction);
        while (intervals.size() > 0) {
            res++;
            int time = 0;
            for (int i = 0; i < intervals.size(); i++) {
                if (time <= intervals[i].start) {
                    time = intervals[i].end;
                    intervals.erase (intervals.begin() + i);
                    i--;
                }
            }
        }
        return res;
    }
};
