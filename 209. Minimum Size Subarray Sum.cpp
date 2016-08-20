class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int l = 0, r = 0, sum = 0, res = INT_MAX;
        while (r < nums.size()) {
            sum += nums[r];
            r++;
            while (sum >= s) {
                res = min (res, r - l);
                sum = sum - nums[l];
                l++;
            }
        }
        return res == INT_MAX? 0 : res;
    }
};
