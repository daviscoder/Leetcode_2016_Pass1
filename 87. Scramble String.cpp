class Solution {
public:
    bool isScramble(string s1, string s2) {
        int len1 = s1.length(), len2 = s2.length();
        if (len1 != len2 || len1 == 0 || len2 == 0) return false;
        vector<vector<vector<bool>>> dp (len1, vector<vector<bool>> (len2, vector<bool> (len1 + 1, false)));
        for (int len = 1; len <= len1; len++) {
            for (int i1 = 0; i1 <= len1 - len; i1++) {
                for (int i2 = 0; i2 <= len1 - len; i2++) {
                    if (len == 1) {
                        dp[i1][i2][len] = s1[i1] == s2[i2]? true : false;
                        continue;
                    }
                    for (int l = 1; l < len; l++) {
                        if ((dp[i1][i2][l] == true && dp[i1 + l][i2 + l][len - l] == true) || (dp[i1][i2 + len - l][l] == true && dp[i1 + l][i2][len - l] == true)) {
                            dp[i1][i2][len] = true;
                            break;
                        }
                    }
                }
            }
        }
        return dp[0][0][len1];
    }
};
