class Solution {
public:
    int helper (int x, long long low, long long high) {
        if (low == high || high - low == 1)
            return low;
        long long mid = low + (high - low) / 2;
        if (mid * mid > x)
            return helper (x, low, mid);
        else
            return helper (x, mid, high);
    }

    int mySqrt(int x) {
        if (x == 1) return 1;
        return helper (x, 0, x / 2 + 1);
    }
};
