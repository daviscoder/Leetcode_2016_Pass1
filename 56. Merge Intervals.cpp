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
    static bool compare (const Interval& i, const Interval& j) {
        return i.start < j.start;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        vector <Interval> res;
        if (intervals.size() == 0)
            return res;
        sort (intervals.begin(), intervals.end(), compare);
        res.push_back (intervals[0]);
        int index = 0;
        for (int i = 1; i < (int)intervals.size(); i++) {
            if (intervals[i].start <= res[index].end) {
                Interval tmp (res[index].start, max (res[index].end, intervals[i].end));
                res.pop_back();
                res.push_back (tmp);
            }
            else {
                res.push_back (intervals[i]);
                index++;
            }
        }
        return res;
    }
};
