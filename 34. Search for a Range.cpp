class Solution {
public:
    vector <int> helper (vector <int>& nums, int target, int start, int end) {
        vector <int> res;
        if (start == end) {
            if (nums[start] == target) {
                res.push_back (start);
                res.push_back (start);
            }
            else {
                res.push_back (-1);
                res.push_back (-1);
            }
            return res;
        }
        int mid = start + (end - start) / 2 + 1;
        if (nums[mid - 1] < target)
            return helper (nums, target, mid, end); // {1,2,3,4,5} [4] // 找右边
        else if (nums[mid] > target)
            return helper (nums, target, start, mid - 1); // 找左边
        else {
            vector <int> left = helper (nums, target, start, mid - 1);
            vector <int> right = helper (nums, target, mid, end);
            res.push_back (left[0]);
            res.push_back (right[1]);
            return res;
        }
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return vector <int> (2, -1);
        return helper (nums, target, 0, nums.size() - 1);
    }
};
