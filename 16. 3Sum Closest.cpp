class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() <= 2)
            return 0;
        sort (nums.begin(), nums.end());
        int res = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
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
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target)
                    return sum;
                if (abs(res - target) > abs(sum - target))
                    res = sum;
                if (sum > target)
                    k--;
                else
                    j++;
            }
        }
        return res;
    }
};
