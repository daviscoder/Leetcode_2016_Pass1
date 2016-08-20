class Solution {
public:
    // In fast, this question can be solved with O(1) space.
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() <= 0)
            return 0;
        vector <vector<int>> dp (matrix.size(), vector <int> (matrix[0].size(), 0));
        int res = 0;
        for (int i = 0; i < matrix.size(); i++) {
            dp[i][0] = matrix[i][0] - '0';
            res = max (res, dp[i][0]);
        }
        for (int i = 0; i < matrix[0].size(); i++) {
            dp[0][i] = matrix[0][i] - '0';
            res = max (res, dp[0][i]);
        }

        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[0].size(); j++) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = min(min (dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                    res = max (res, dp[i][j]);
                }
                else
                    dp[i][j] = 0;
            }
        }
        return res * res;
    }
};
