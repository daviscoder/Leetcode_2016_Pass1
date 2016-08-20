class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res (nums.size(), 1);
        int lp = 1, rp = 1;
        for (int i = 0; i < nums.size(); i++) {
            res[i] = lp;
            lp *= nums[i];
        }
        for (int i = nums.size() - 1; i >= 0; i--) {
            res[i] = res[i] * rp;
            rp *= nums[i];
        }
        return res;
    }
};
