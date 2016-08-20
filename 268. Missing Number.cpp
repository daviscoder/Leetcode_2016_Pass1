class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int total = 0;
        for (int i = 1; i <= nums.size(); i++)
            total += i - nums[i - 1];
        return total;
    }
};
