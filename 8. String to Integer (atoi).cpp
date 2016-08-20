class Solution {
public:
    int myAtoi(string str) {
        int cnt, res = 0;
        bool positive = true;
        for (cnt = 0; cnt < str.length() && str[cnt] == ' '; cnt++) {};
        if (cnt < str.length() && str[cnt] == '-')
            positive = false;
        if (cnt < str.length() && (str[cnt] == '-' || str[cnt] == '+'))
            cnt++;
        for (;cnt < str.length() && str[cnt] >= '0' && str[cnt] <= '9'; cnt++) {
            if (positive == true && (INT_MAX - str[cnt] + '0') / 10 >= res)
                res = res * 10 + str[cnt] - '0';
            else if (positive == false && (INT_MIN + str[cnt] - '0') / 10 <= res * -1)
                res = res * 10 + str[cnt] - '0';
            else if (positive == true)
                return INT_MAX;
            else 
                return INT_MIN;
        }
        return positive == true? res : res * -1;
        
    }
};
