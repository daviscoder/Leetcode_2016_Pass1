class Solution {
public:
    int numWays(int n, int k) {
        if (n == 0) return 0;
        if (n == 1) return k;
        if (n == 2) return k * k;
        int same = k, diff = k * (k - 1);
        for (int i = 3; i <= n; i++) {
            int new_same = diff;
            int new_diff = (same + diff) * (k - 1);
            same = new_same;
            diff = new_diff;
        }
        return same + diff;
    }
};
