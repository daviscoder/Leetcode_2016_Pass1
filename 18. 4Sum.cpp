class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums, int target, int start) {
        vector <vector<int>> res;
        if (nums.size() < 3)
            return res;
//        sort (nums.begin(), nums.end());
        for (int i = start; i < nums.size() - 2; i++) {
            if(i > start && nums[i] == nums[i - 1])
                continue;
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    j++;
                    continue;
                }
                if (k < nums.size() - 1 && nums[k] == nums[k + 1]) {
                    k--;
                    continue;
                }
                
                if (nums[i] + nums[j] + nums[k] == target) {
                    vector <int> tmp;
                    tmp.push_back (nums[i]);
                    tmp.push_back (nums[j]);
                    tmp.push_back (nums[k]);
                    res.push_back (tmp);
                    j++;
                    k--;
                }
                else if (nums[i] + nums[j] + nums[k] < target)
                    j++;
                else
                    k--;
            }
        }
        return res;
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector <vector<int>> res;
        if (nums.size() < 4)
            return res;
        sort (nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            vector <vector<int>> ret = threeSum (nums, target - nums[i], i + 1);
            for (int j = 0; j < (int) ret.size(); j++) {
                vector <int> tmp (1, nums[i]);
                tmp.insert (tmp.end(), ret[j].begin(), ret[j].end());
                res.push_back (tmp);
            }
        }
        return res;
    }
};
