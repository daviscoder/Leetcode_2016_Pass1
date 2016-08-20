class Solution {
public:
    int numDistinct(string s, string t) {
        int len1 = s.length(), len2 = t.length();
        if (len1 == 0 || len2 == 0) return 0;
        vector<vector<int>> dp (len2 + 1, vector<int> (len1 + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= len2; i++) {
            for (int j = 1; j <= len1; j++) {
                dp[0][j] = 1;
                if (t[i - 1] == s[j - 1])
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
                else
                    dp[i][j] = dp[i][j - 1];
            }
        }
        return dp[len2][len1];
    }
};
