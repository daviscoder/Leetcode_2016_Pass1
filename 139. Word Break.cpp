class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int size = s.size();
        vector<bool> dp (size + 1, false);
        dp[0] = true;
        for (int i = 1; i <= size; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && wordDict.count (s.substr (j, i - j)))
                    dp[i] = true;
            }
        }
        return dp[size];
    }
};
