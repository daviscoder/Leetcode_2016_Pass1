class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length(); 
        vector<vector<bool> > dp(m + 1, vector<bool> (n + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= n; i++) { //第一行：reg和空字串匹配：只会出现用*消除前一个字符标为1的状况，其他全0.
            if (p[i - 1] == '*') {
                if (i >= 2) //分开写为了防止溢出.
                    dp[0][i] = dp[0][i - 2];
            }
        }
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == '.') //必须匹配当前字符.
                    dp[i][j] = dp[i - 1][j - 1];
                else if (p[j - 1] == '*') {
                /*
                  三种情况: 
                    1. *本身忽略，相当于*不起作用: dp[i][j]=dp[i][j - 1]
                    2. *删除前一个字符: dp[i][j - 2]
                    3. *重复之前字符: dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'
                */
                    dp[i][j]=dp[i][j - 1] || (dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.')) || dp[i][j - 2];
                }
                else { // 字母匹配.
                    dp[i][j] = dp[i - 1][j - 1] && s[i - 1] == p [j - 1];
                }
            }
        }
        return dp[m][n];
    }
};
