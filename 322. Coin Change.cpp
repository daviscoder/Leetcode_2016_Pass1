class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (coins.size() <= 0 || amount <= 0)
            return 0;
        sort (coins.begin(), coins.end());
        vector <int> dp (amount + 1, 0);
        for (int i = 1; i <= amount; i++) {
            int cur = INT_MAX;
            for (int j = 0; j < coins.size() && coins[j] <= i; j++) {
                if (dp[i - coins[j]] != INT_MAX)
                    cur = min (cur, 1 + dp[i - coins[j]]);
            }
            dp[i] = cur;
        }
        return dp[amount] == INT_MAX? -1 : dp[amount];
    }
};
