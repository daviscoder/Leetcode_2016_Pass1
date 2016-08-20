class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if (nums.size() <= 0) // WHY????????
            return;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (i % 2 == 0 && nums[i] > nums[i + 1]) {
                int tmp = nums[i];
                nums[i] = nums[i + 1];
                nums[i + 1] = tmp;
            }
            else if (i % 2 != 0 && nums[i] < nums[i + 1]) {
                int tmp = nums[i];
                nums[i] = nums[i + 1];
                nums[i + 1] = tmp;
            }
        }
    }
};
