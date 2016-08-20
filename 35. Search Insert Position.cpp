class Solution {
public:
    int helper (vector <int>& nums, int target, int begin, int end) {
        if (begin == end) {
            if (nums[begin] < target)
                return end + 1;
            else if (nums[begin] >= target)
                return 0;
        }
        int mid = begin + (end - begin) / 2 + 1;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            return helper (nums, target, mid, end);
        else
            return helper (nums, target, begin, mid - 1);
    }

    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return 0;
        return helper (nums, target, 0, nums.size() - 1);
    }
};
