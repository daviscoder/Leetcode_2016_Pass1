class Solution {
public:
    void helper (vector<vector<int>>& res, vector<int>& cur, vector<int>& nums, int i) {
        if (i == nums.size()) {
            res.push_back (cur);
            return;
        }
        helper (res, cur, nums, i + 1);
        cur.push_back (nums[i]);
        helper (res, cur, nums, i + 1);
        cur.pop_back ();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() == 0) return res;
        vector<int> cur;
        helper (res, cur, nums, 0);
        return res;
    }
};
