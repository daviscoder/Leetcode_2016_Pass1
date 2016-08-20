class Solution {
public:
    vector<vector<int>> helper (vector<int>& nums, int begin) {
        vector<vector<int>> res;
        if (begin == nums.size() - 1) {
            res.push_back (vector<int> (1, nums[begin]));
            return res;
        }
        for (int i = begin; i < (int)nums.size(); i++) {
            int tmp = nums[begin];
            nums[begin] = nums[i];
            nums[i] = tmp;
            vector<vector<int>> p2 = helper (nums, begin + 1);
            for (int i = 0; i < p2.size(); i++) {
                vector<int> tmp (1, nums[begin]);
                tmp.insert (tmp.end(), p2[i].begin(), p2[i].end());
                res.push_back (tmp);
            }
            tmp = nums[begin];
            nums[begin] = nums[i];
            nums[i] = tmp;

        }
        return res;
    }

    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.size() == 0)
            return vector <vector<int>> ();
        return helper (nums, 0);
    }
};
