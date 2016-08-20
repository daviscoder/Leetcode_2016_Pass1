class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int cnt1 = 0, cnt2 = 0, num1 = 0, num2 = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == num1)
                cnt1++;
            else if (nums[i] == num2)
                cnt2++;
            else if (cnt1 == 0) {
                cnt1 = 1;
                num1 = nums[i];
            }
            else if (cnt2 == 0) {
                cnt2 = 1;
                num2 = nums[i];
            }
            else {
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0;
        cnt2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == num1)
                cnt1++;
            else if (nums[i] == num2)
                cnt2++;
        }
        if (cnt1 > nums.size() / 3)
            res.push_back (num1);
        if (cnt2 > nums.size() / 3)
            res.push_back (num2);
        return res;
    }
};
