class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() <= 1)
            return 0;
        int left = 0, right = height.size() - 1, res = 0;
        while (left < right) {
            res = max (res, (right - left) * min (height[left], height[right]));
            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        return res;
    }
};
