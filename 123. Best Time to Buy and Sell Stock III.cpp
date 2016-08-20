class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        int K = 2, maxProf = 0;
        vector <vector<int>> dp (K + 1, vector<int> (prices.size(), 0));
        for (int i = 1; i <= K; i++) {
            int tmpMax = -prices[0];
            for (int j = 1; j < prices.size(); j++) {
                dp[i][j] = max (dp[i][j - 1], prices[j] + tmpMax);
                tmpMax = max (tmpMax, dp[i - 1][j] - prices[j]);
                maxProf = max (maxProf, dp[i][j]);
            }
        }
        return maxProf;
    }
};
