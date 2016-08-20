class Solution {
public:
    int helper (vector<int>& nums, int l, int r) {
        if (l == r)
            return nums[l];
        int mid = l + (r - l) / 2;
        if (nums[mid] < nums[r])
            return helper (nums, l, mid);
        else
            return helper (nums, mid + 1, r);
    }
    int findMin(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        return helper (nums, 0, nums.size() - 1);
    }
};
