class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        vector<vector<bool>> dp(m + 1, vector<bool> (n + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= n; i++) {
            if (p[i] == '*')
                dp[0][i + 1] = true;
            else
                break;
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (p[j] == '*')
                    dp[i + 1][j + 1] = dp[i + 1][j] || dp[i][j + 1];
                else if (p[j] == '?')
                    dp[i + 1][j + 1] = dp[i][j];
                else
                    dp[i + 1][j + 1] = dp[i][j] && s[i] == p[j];
            }
        }
        return dp[m][n];
    }
};
