class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.size() == 0) return false;
        int start = 0, end = nums.size() - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target)
                return true;
            if (nums[mid] < nums[end]) { // left half.
                if (target > nums[mid] && target <= nums[end])
                    start = mid + 1;
                else
                    end = mid - 1;
            }
            else if (nums[mid] > nums[end]) { // right half.
                if (target >= nums[start] && target < nums[mid])
                    end = mid - 1;
                else
                    start = mid + 1;
            }
            else
                end--;
        }
        return false;
    }
};
