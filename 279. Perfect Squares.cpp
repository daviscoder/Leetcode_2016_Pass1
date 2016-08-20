class Solution {
public:
    int numSquares(int n) {
        vector <int> res (n + 1, INT_MAX);
        res[0] = 0;
        for (int i = 1; i < n + 1; i++)
            for (int j = i * i; j < n + 1; j++)
                res [j] = min (res[j], res[j - i * i] + 1);
        return res[n];
    }
};
