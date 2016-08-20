class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m <= 1 || n <= 1)
            return 1;
        if (m > n)
            swap (m, n);
        double res = 1;
        for (int i = 1; i < m; i++) {
            res *= m + n - 2 - i + 1;
            res /= i;
        }
        return res;
    }
};
