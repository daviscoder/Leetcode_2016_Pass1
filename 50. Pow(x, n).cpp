class Solution {
public:
    double compute (double x, int n) {
        if (n == 0)
            return 1;
        double res = compute (x, n / 2);
        res *= res;
        if (n % 2)
            res *= x;
        return res;
    }

    double myPow(double x, int n) {
        if (n < 0)
            return 1 / compute (x, -n);
        else
            return compute (x, n);
    }
};
