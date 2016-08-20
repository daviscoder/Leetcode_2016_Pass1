// http://bangbingsyb.blogspot.com/2014/11/leetcode-palindrome-partitioning-i-ii.html
class Solution {
public:
    int minCut(string s) {
        if (s.size() == 0) return 0;
        int n = s.size();
        vector<vector<int>> isPal (n, vector<int> (n, false));
        vector<int> dp (n + 1, INT_MAX);
        dp[0] = -1;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if ((i + 1 > j - 1 || isPal[i + 1][j - 1] == true) && s[i] == s[j])
                    isPal[i][j] = true;
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (isPal[j][i - 1] == true)
                    dp[i] = min (dp[i], dp[j] + 1);
            }
        }
        return dp[n];
    }
};
