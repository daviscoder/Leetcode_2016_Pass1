class Solution {
public:
    void helper (vector<int>& nums, vector<int>& cur, vector<vector<int>>& res, int start) {
        res.push_back (cur);
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1])
                continue;
            cur.push_back (nums[i]);
            helper (nums, cur, res, i + 1);
            cur.pop_back ();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        if (nums.size() == 0)
            return res;
        sort (nums.begin(), nums.end());
        helper (nums, cur, res, 0);
        return res;
    }
};
