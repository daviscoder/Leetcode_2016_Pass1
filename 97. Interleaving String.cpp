class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) return false;
        vector<vector<bool>> dp (s1.length() + 1, vector<bool> (s2.length() + 1, false));
        dp[0][0] = true;
        for (int j = 1; j < s2.length() + 1; j++) {
            if (s2[j - 1] == s3[j - 1])
                dp[0][j] = true;
            else
                break;
        }
        for (int i = 1; i < s1.length() + 1; i++) {
            if (s1[i - 1] == s3[i - 1])
                dp[i][0] = true;
            else
                break;
        }
        for (int i = 1; i < s1.length() + 1; i++) {
            for (int j = 1; j < s2.length() + 1; j++) {
                if (s1[i - 1] == s3[i + j - 1] && dp[i - 1][j] == true)
                    dp[i][j] = true;
                else if (s2[j - 1] == s3[i + j - 1] && dp[i][j - 1] == true)
                    dp[i][j] = true;
            }
        }
        return dp[s1.length()][s2.length()];
    }
};
