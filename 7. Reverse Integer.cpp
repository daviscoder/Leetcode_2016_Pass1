class Solution {
public:
    int reverse(int x) {
        bool positive = x >= 0? true : false;
        x = abs (x);
        int res = 0;
        while (x) {
            if (positive == true && (INT_MAX - x % 10) / 10 >= res) {
                res = res * 10 + x % 10;
                x /= 10;
            }
            else if (positive == false && (INT_MIN + x % 10) / 10 <= res * -1) {
                res = res * 10 + x % 10;
                x /= 10;
            }
            else
                return 0;
        }
        return positive == true? res : res * -1;
    }
};
