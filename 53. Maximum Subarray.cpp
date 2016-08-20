class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() <= 0)
            return 0;
        int max_end_here = nums[0], max_so_far = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            max_end_here = max (nums[i], nums[i] + max_end_here);
            max_so_far = max (max_end_here, max_so_far);
        }
        return max_so_far;
    }
};


---以下为DC 解法.

class Solution {
public:
    int findMaxInCross (vector <int> & nums, int begin, int mid, int end) {
        int leftSum = INT_MIN, sum = 0, rightSum = INT_MIN;
        for (int i = mid - 1; i >= begin; i--) {
            sum += nums[i];
            if (sum > leftSum) 
                leftSum = sum;
        }
        sum = 0;
        for (int i = mid; i <= end; i++) {
            sum += nums[i];
            if (sum > rightSum)
                rightSum = sum;
        }
        return leftSum + rightSum;
    }
    
    int solver (vector <int>& nums, int begin, int end) {
        if (begin == end) 
            return nums[begin];
        int mid = begin / 2 + end / 2 + 1;
        return max (max(solver (nums, begin, mid - 1), solver (nums, mid, end)), findMaxInCross (nums, begin, mid, end));
    }

    int maxSubArray(vector<int>& nums) {
        if (nums.size() <= 0)
            return 0;
        return solver (nums, 0, nums.size() - 1);
    }
};
