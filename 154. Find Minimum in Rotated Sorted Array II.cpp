class Solution {
public:
    int helper (vector<int>& nums, int start, int end) {
        if (start == end)
            return nums[start];
        int mid = start + (end - start) / 2;
        if (nums[mid] > nums[end])
            return helper (nums, mid + 1, end);
        else if (nums[mid] < nums[end])
            return helper (nums, start, mid);
        else
            return helper (nums, start, end - 1);
    }

    int findMin(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        return helper (nums, 0, nums.size() - 1);
    }
};
