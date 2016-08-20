class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0 || obstacleGrid[0][0] == 1 || obstacleGrid[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1] == 1)
            return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> dp (n, 0);
        for (int i = 0; i < n; i++)
            if (obstacleGrid[0][i] == 0)
                dp [i] = 1;
            else
                break;
        for (int i = 1; i < m; i++) {
            dp[0] = dp[0] && !obstacleGrid[i][0];
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1)
                    dp[j] = 0;
                else {
                    dp[j] = dp[j] + dp[j - 1];
                }
            }
        }
        return dp[n - 1];
    }
};
