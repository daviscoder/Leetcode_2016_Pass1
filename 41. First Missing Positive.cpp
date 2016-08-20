class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if (nums.size() == 0)
            return 1;
        else if (nums.size() == 1)
            return nums[0] == 1? 2 : 1;
        for (int i = 0; i < (int)nums.size(); i++)
            if (nums[i] >= 0 && nums[i] < nums.size() && nums[i] != i && nums[nums[i]] != nums[i]) {
                swap (nums[i], nums[nums[i]]);
                i--;
            }
        int i = 1;
        while (i == nums[i] && i < nums.size())
            i++;
        if (i < nums.size())
            return i;
        return nums[0] == i? i + 1 : i;
    }
};
