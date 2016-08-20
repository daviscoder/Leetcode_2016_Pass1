class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() <= 0)
            return 0;
        int curMax = nums[0], curMin = nums[0], res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int tmpMax = curMax, tmpMin = curMin;
            curMax = max (max (tmpMax * nums[i], tmpMin * nums[i]), nums[i]);
            curMin = min (min (tmpMax * nums[i], tmpMin * nums[i]), nums[i]);
            res = max (res, curMax);
        }
        return res;
    }
};
