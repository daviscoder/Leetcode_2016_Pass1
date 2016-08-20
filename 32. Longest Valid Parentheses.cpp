class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.size() == 0)
            return 0;
        vector <int> dp (s.size() + 1, 0);
        int res = 0;
        for (int i = 1; i < s.size() + 1; i++) {
            int j = i - dp[i - 1] - 2;
            if (s[i - 1] == '(' || j < 0 || s[j] == ')')
                dp[i] = 0;
            else {
                dp[i] = dp[i - 1] + dp[j] + 2;
                res = max (res, dp[i]);
            }
        }
        return res;
    }
};
