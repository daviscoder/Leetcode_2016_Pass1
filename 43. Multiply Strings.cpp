class Solution {
public:

    string multiply1Digit (string num, int gap, int c) {
        if (c == 0)
            return "";
        string res (gap, '0');
        int carry = 0;
        for (int i = 0; i < num.length(); i++) {
            int product = (num[i] - '0') * c + carry;
            res += to_string (product % 10);
            carry = product / 10;
        }
        if (carry)
            res += to_string (carry);
        return res;
    }    

    string sum (string s1, string s2) {
        int carry = 0;
        string res;
        int i = 0;
        while (i < s1.size() || i < s2.size() || carry) {
            int cur = carry;
            if (i < s1.size())
                cur += s1[i] - '0';
            if (i < s2.size())
                cur += s2[i] - '0';
            res += to_string (cur % 10);
            carry = cur / 10;
            i++;
        }
        return res;
    }
    
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";
        int m = num1.length(), n = num2.length();
        reverse (num1.begin(), num1.end());
        reverse (num2.begin(), num2.end());
        vector <string> array;
        for (int i = 0; i < n; i++) {
            array.push_back (multiply1Digit (num1, i, num2[i] - '0'));
        }
        string res;
        for (int i = 0; i < array.size(); i++) {
            res = sum (array[i], res);
        }
        reverse (res.begin(), res.end());
        return res;
        
    }
};
