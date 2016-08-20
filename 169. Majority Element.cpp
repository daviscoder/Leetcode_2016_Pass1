class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = nums[0], cnt = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == res)
                cnt++;
            else if (cnt == 0) {
                cnt = 1;
                res = nums[i];
            }
            else
                cnt--;
        }
        return res;
    }
};
