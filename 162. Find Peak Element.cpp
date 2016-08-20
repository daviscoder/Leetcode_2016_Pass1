class Solution {
public:
    int helper (vector<int>& nums, int start, int end) {
        if (start == end)
            return start;
        int mid = start + (end - start) / 2;
        if ((mid == 0 || nums[mid] > nums[mid - 1]) && (mid == nums.size() - 1 || nums[mid] > nums[mid + 1]))
            return mid;
        else if (nums[mid] < nums[mid + 1])
            return helper (nums, mid + 1, end);
        else
            return helper (nums, start, mid - 1);
    }
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        return helper (nums, 0, nums.size() - 1);
    }
};
