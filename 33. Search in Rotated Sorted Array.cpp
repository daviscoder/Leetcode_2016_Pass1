class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return -1;
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[left] <= nums[mid]) {
                if (target >= nums[left] && target <= nums[mid]) {
                    right = mid;
                }
                else {
                    left = mid + 1;
                }
            }
            else {
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid + 1;
                }
                else {
                    right = mid;
                }
            }
        }
        if (left == right && nums[left] == target)
            return left;
        return -1;
    }
};
