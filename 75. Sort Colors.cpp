class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.size() == 0) return;
        int r = 0, b = (int)nums.size() - 1;
        for (int i = 0; i <= b;) {
            if (nums[i] == 0) {
                swap (nums[i], nums[r]);
                r++;
                i++;
            }
            else if (nums[i] == 2) {
                swap (nums[i], nums[b]);
                b--;
            }
            else
                i++;
        }
    }
};
