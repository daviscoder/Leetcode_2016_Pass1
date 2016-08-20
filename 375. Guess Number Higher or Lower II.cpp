class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp (n + 1, vector<int> (n + 1, 0));
        for (int L = n - 1; L > 0; L--) {
            for (int R = L + 1; R <= n; R++) {
                dp[L][R] = INT_MAX;
                for (int i = L; i < R; i++)
                    dp[L][R] = min (dp[L][R], i + max (dp[L][i - 1], dp[i + 1][R]));
            }
        }
        return dp[1][n];
    }
};
