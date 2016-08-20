class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) // The only chance to overflow.
            return INT_MAX;
        if (divisor == 0)
            return dividend >= 0? INT_MAX : INT_MIN;
        bool positive = ((dividend >= 0 && divisor < 0) || (dividend < 0 && divisor >= 0))? false : true;
        unsigned long long dvd = abs((long long)dividend);
        unsigned long long dvs = abs((long long)divisor);
        unsigned long long dvs_original = dvs;
        
        int cnt = 0, res = 0;
        while (dvs << (cnt + 1) <= dvd)
            cnt++;

        while (dvd >= dvs_original) {
            if (dvd >= dvs << cnt) {
                res += 1 << cnt;
                dvd -= dvs << cnt;
            }
            cnt--;
        }
        return positive == true? res : -res;
    }
};
