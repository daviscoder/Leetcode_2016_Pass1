// http://fisherlei.blogspot.com/2015/10/leetcode-single-number-iii-solution.html
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorBoth = 0;
        for (int i = 0; i < nums.size(); i++)
            xorBoth ^= nums[i];
        int k = 0;
        for (; k < 32; k++)
            if ((xorBoth >> k) & 1)
                break;
        int res1 = 0, res2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if ((nums[i] >> k) & 1)
                res1 ^= nums[i];
            else
                res2 ^= nums[i];
        }
        vector <int> res = {res1, res2};
        return res;
    }
};
