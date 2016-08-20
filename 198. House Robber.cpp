class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() <= 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        int prev = nums[0], prevPrev = 0, prevPrevPrev = 0, cur = 0, res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            cur = max (prevPrevPrev, prevPrev) + nums[i];
            res = max (res, cur);
            prevPrevPrev = prevPrev;
            prevPrev = prev;
            prev = cur;
        }
        return res;
    }
};
