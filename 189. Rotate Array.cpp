class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        vector<int>::iterator it;
        for (int i = 0; i < k; i++) {
            it = nums.begin();
            nums.insert (it, nums[nums.size() - 1]);
            nums.pop_back ();
        }
    }
};
