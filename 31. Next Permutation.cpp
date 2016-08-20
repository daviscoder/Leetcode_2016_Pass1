class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1)
            return;
        int i;
        for (i = nums.size() - 1; i > 0; i--)
            if (nums[i - 1] < nums[i])
                break;
        if (i == 0) {
            reverse (nums.begin(), nums.end());
            return;
        }
        int target = nums[i], index = i;
        for (int j = nums.size() - 1; j > i; j--) {
            if (nums[j] < target && nums[j] > nums[i - 1]) {
                target = nums[j];
                index = j;
            }
        }
        swap (nums[i - 1], nums[index]);
        sort (nums.begin() + i, nums.end());
    }
};

---- better solution.

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1)
            return;
        int i;
        for (i = nums.size() - 1; i > 0; i--)
            if (nums[i - 1] < nums[i])
                break;
        if (i == 0) {
            reverse (nums.begin(), nums.end());
            return;
        }
        int target = INT_MAX, index = i;
        for (int j = nums.size() - 1; j >= i; j--) {
            if (nums[j] < target && nums[j] > nums[i - 1]) {
                target = nums[j];
                index = j;
            }
        }
        swap (nums[i - 1], nums[index]);
        reverse (nums.begin() + i, nums.end());
    }
};
