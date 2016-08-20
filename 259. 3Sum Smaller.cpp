class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int res = 0;
        sort (nums.begin(), nums.end());
        for (int i = 0; i + 2< nums.size(); i++) {
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                if (nums[left] + nums[right] + nums[i] < target) {
                    res += right - left;
                    left++;
                }
                else
                    right--;
            }
        }
        return res;
    }
};
