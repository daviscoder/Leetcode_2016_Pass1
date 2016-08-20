class Solution {
public:
    int shortcut (vector<int>& prices) {
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) 
            if (prices[i] > prices[i - 1])
                profit += (prices[i] - prices[i - 1]);
        return profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        if (k > prices.size() / 2)
            return shortcut (prices);
        int maxProf = 0;
        vector<int> dp (prices.size(), 0);
        for (int i = 1; i <= k; i++) {
            int prev = dp[0];
            int tmpMax = -prices[0];
            for (int j = 1; j < prices.size(); j++) {
                cout << maxProf << "\t";
                tmpMax = max (tmpMax, dp[j] - prices[j]);
                dp[j] = max (prev, prices[j] + tmpMax);
                maxProf = max (maxProf, dp[j]);
                prev = dp[j];
            }
        }
        return maxProf;
    }
};
