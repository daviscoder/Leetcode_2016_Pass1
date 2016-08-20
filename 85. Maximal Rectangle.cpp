class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.size() == 0) return 0;
        stack <int> S;
        int res = 0;
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
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return 0;
        vector<int> h (matrix[0].size() + 1, 0);
        int res = 0;
        for (int i = 0; i < matrix[0].size(); i++)
            h[i] = matrix[0][i] == '1'? 1 : 0;
        res = largestRectangleArea (h);
        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                h[j] = matrix[i][j] == '0'? 0 : h[j] + 1;
            }
            res = max (res, largestRectangleArea (h));
        }
        return res;
    }
};
