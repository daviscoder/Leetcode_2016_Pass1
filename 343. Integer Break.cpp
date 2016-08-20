class Solution {
public:
    int integerBreak(int n) { //找规律题
        int result = 1;
        if (n == 1 || n == 2)
            return 1;
        else if (n == 3)
            return 2;
        while (n > 4) {
            result *= 3;
            n -= 3;
        }
        return result * n;
    }
};
