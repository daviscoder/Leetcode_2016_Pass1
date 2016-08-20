class Solution {
public:
    void push_range (vector<int>& nums, vector<string>& res, int j, int i) {
        if (i == j)
            res.push_back (to_string (nums[j]));
        else
            res.push_back (to_string (nums[j]) + "->" + to_string (nums[i]));
    }
    
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if (nums.size() == 0) return res;
        if (nums.size() == 1) {
            res.push_back (to_string (nums[0]));
            return res;
        }
        int j = 0;
        for (int i = 1; i < nums.size();) {
            if (i == nums.size() - 1) {
                if (nums[i] == nums[i - 1] + 1)
                    push_range (nums, res, j, i);
                else {
                    push_range (nums, res, j, i - 1);
                    push_range (nums, res, i, i);
                }
                break;
            }
            else if (i != j && nums[i] - nums[j] != i - j) {
                push_range (nums, res, j, i - 1);
                j = i;
            }
            else
                i++;
        }
        return res;
    }
};
