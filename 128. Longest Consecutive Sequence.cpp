// http://bangbingsyb.blogspot.com/2014/11/leetcode-longest-consecutive-sequence.html

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        unordered_set <int> my_set;
        int res = 1;
        for (int i = 0; i < nums.size(); i++)
            my_set.insert (nums[i]);
        for (int i = 0; i < nums.size(); i++) {
            if (my_set.empty())
                break;
            int curLen = 0, curNum = nums[i];
            while (my_set.count (curNum)) {
                my_set.erase (curNum);
                curNum++;
                curLen++;
            }
            curNum = nums[i] - 1;
            while (my_set.count (curNum)) {
                my_set.erase (curNum);
                curNum--;
                curLen++;
            }
            res = max (res, curLen);
        }
        return res;
    }
};
