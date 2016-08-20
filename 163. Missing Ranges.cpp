class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        int prev = lower - 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > prev + 1) {
                int start = prev + 1, end = nums[i] - 1;
                if (start == end)
                    res.push_back (to_string (start));
                else {
                    string tmp = to_string (start) + "->" + to_string (end);
                    res.push_back (tmp);
                }
            }
            prev = nums[i];
        }
        if (prev != upper) {
            int start = prev + 1, end = upper;
            if (start == end)
                res.push_back (to_string (upper));
            else {
                string tmp = to_string (start) + "->" + to_string (end);
                res.push_back (tmp);
            }
        }
        return res;
    }
};
