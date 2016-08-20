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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        if (intervals.size() == 0 || intervals[intervals.size() - 1].end < newInterval.start) {
            intervals.push_back (newInterval);
            return intervals;
        }
        else if (intervals[0].start > newInterval.end) {
            intervals.insert (intervals.begin(), newInterval);
            return intervals;
        }
        int begin = 0, end = 0;
        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i].end < newInterval.start)
                begin++;
            if (intervals[i].start <= newInterval.end)
                end++;
        }
        cout << begin << "\t" << end << endl;
        int new_start = min (newInterval.start, intervals[begin].start);
        int new_end = max (newInterval.end, intervals[end - 1].end);
        Interval tmp (new_start, new_end);
        intervals.erase (intervals.begin() + begin, intervals.begin() + end);
        intervals.insert (intervals.begin() + begin, tmp);
        return intervals;
    }
};
