class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 0 || triangle[0].size() == 0)
            return 0;
        vector <int> dp (triangle.size(), 0);
        int res = INT_MAX;
        dp[0] = triangle[0][0];
        for (int i = 1; i < triangle.size(); i++) {
            int last = dp[0];
            dp[0] = triangle[i][0] + dp[0];
            for (int j = 1; j < i; j++) {
                int tmp = dp[j];
                dp[j] = min (last, dp[j]) + triangle[i][j];
                last = tmp;
            }
            dp[i] = last + triangle[i][i];
            for (int i = 0; i < dp.size(); i++)
                cout << dp[i] << " ";
            cout << endl;

        }
        for (int i = 0; i < dp.size(); i++)
            res = min (dp[i], res);
        return res;
    }
};
