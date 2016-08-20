class Solution {
public:
// http://www.cnblogs.com/lichen782/p/leetcode_Largest_Rectangle_in_Histogram.html
    int largestRectangleArea(vector<int>& heights) {
        if (heights.size() == 0) return 0;
        stack <int> S;
        int res = 0;
        heights.push_back (0);
        for (int i = 0; i < heights.size(); i++) {
            if (S.empty() || heights[S.top()] <= heights[i])
                S.push (i);
            else {
                int t = S.top();
                S.pop();
                int l = S.empty()? 0 : S.top() + 1;
                res = max (res, heights[t] * (i - l));
                i--;
            }
        }
        return res;
    }
};
