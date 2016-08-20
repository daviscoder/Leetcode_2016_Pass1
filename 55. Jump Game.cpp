class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() <= 1)
            return true;
        int p = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (i > nums[p] + p)
                return false;
            if (nums[i] + i >= nums.size() - 1)
                return true;
            if (nums[p] + p < nums[i] + i) 
                p = i;
        }
        return false;
    }
};
