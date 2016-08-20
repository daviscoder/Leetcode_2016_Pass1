class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert (nums.begin(), 1);
        nums.insert (nums.end(), 1);
        vector<vector<int>> dp (n + 2, vector<int> (n + 2, 0));
        for (int i = n; i >= 1; i--) {
            for (int j = i; j <= n; j++) {
                dp[i][j] = INT_MIN;
                for (int k = i; k <= j; k++) {
                    dp[i][j] = max (dp[i][j], dp[i][k - 1] + dp[k + 1][j] + nums[k] * nums[i - 1] * nums[j + 1]);
                }
            }
        }
        return dp[1][n];
    }
};
