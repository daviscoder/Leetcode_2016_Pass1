/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        unordered_map<double, int> gradient;
        int res = 0;
        for (int i = 0; i < points.size(); i++) {
            int duplicate = 1;
            gradient.clear();
            gradient[INT_MIN] = 0;
            for (int j = 0; j < points.size(); j++) {
                if (i == j) continue;
                if (points[i].x == points[j].x && points[i].y == points[j].y) {
                    duplicate++;
                    continue;
                }
                double key = 0;
                if (points[i].x == points[j].x)
                    key = INT_MAX;
                else
                    key = ((double) points[i].y - points[j].y) / (points[i].x - points[j].x);
                gradient[key]++;
            }
            for (unordered_map<double, int>::iterator it = gradient.begin(); it != gradient.end(); it++)
                res = max (res, it->second + duplicate);
        }
        return res;
    }
};
