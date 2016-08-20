class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 1)
            return 10;
        if (n == 0)
            return 1;
        if (n > 10 || n < 0)
            return 0;
        vector <int> table (n + 1, 0);
        table[1] = 10;
        for (int i = 2; i <= n; i++) {
            int tmp = 9;
            for (int j = 9; j > 9 - i + 1; j--)
                tmp *= j;
            table[i] = tmp + table[i - 1];
        }
        return table[n];
    }
};
