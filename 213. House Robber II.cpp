class Solution {
public:
int rob(vector<int>& nums) {
    if (nums.size() <= 0)
        return 0;
    if (nums.size() == 1)
        return nums[0];
    int a0 = 0, a1 = nums[1], a2 = a1, res;
    for (int i = 2; i < nums.size(); i++) {
        a2 = max (a0 + nums[i], a1);
        a0 = a1;
        a1 = a2;
    }
    res = a2;
    a0 = 0;
    a1 = nums[0];
    a2 = a1;
    for (int i = 1; i < nums.size() - 1; i++) {
        a2 = max (a0 + nums[i], a1);
        a0 = a1;
        a1 = a2;
    }
    return max (a2, res);
}};
