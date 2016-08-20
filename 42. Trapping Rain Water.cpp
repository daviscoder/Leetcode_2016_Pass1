class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() <= 2)
            return 0;
        vector <int> maxL (height.size(), 0);
        vector <int> maxR (height.size(), 0);
        int curMax = height[0], res = 0;
        for (int i = 1; i < height.size() - 1; i++) {
            maxL[i] = curMax;
            curMax = max (curMax, height[i]);
        }
        curMax = height[height.size() - 1];
        for (int i = height.size() - 2; i > 0; i--) {
            maxR[i] = curMax;
            curMax = max (curMax, height[i]);
            if (min (maxL[i], maxR[i]) - height[i] > 0) {
                res += min (maxL[i], maxR[i]) - height[i];
            }
        }
        return res;
    }
};
