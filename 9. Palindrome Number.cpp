class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        int cnt = 0, num = x; //number of digits.
        while (num) {
            num /= 10;
            cnt++;
        }
        while (cnt > 1) {
            if (x / (int)pow (10, cnt - 1) != x % 10)
                return false;
            x = (x % (int) pow (10, cnt - 1)) / 10;
            cnt -= 2;
        }
        return true;
    }
};
